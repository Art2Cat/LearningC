procedure getPartySSIListByMei
  (
    p_resultset   out sys_refcursor
   ,p_status        in varchar2 default null
   ,p_partyId       in number default null
   ,p_profileId     in number default null
   ,p_sortByCcy     in number default null
  ) as
  begin
      open p_resultset for
        with getAppliedToADFVW as (
          select si.ssi_reference_id as si_id from ADF_SSI_SETTINGS ass
          inner join cp_acct_trade cat 
          on (ass.trade_acct_id = cat.trade_acct_id)
          inner join party p
          on (cat.mei = p.party_mei)
          inner join settlement_instruction si
          on (ass.ssi_id = si.ssi_reference_id)
          where p.party_id =  p_partyId
          and ass.is_applied_to_adf = 1
        )
      
        select SI.SSI_REFERENCE_ID as ssiReferenceID
              ,SI.CURRENCY as currency
              ,case
                when (select count(1) from getAppliedToADFVW where si_id = SI.SSI_REFERENCE_ID) > 0 then
                1
                else
        0
         end as appliedToADF
              ,SI.PARTY_TYPE as partyType
              ,SI.EFFECTIVE_DATE as effectiveDate
              ,SI.CORRESPONDENT_CODE as correspondentBankSwiftCode
              ,SI.CORRESPONDENT_NAME as correspondentBankName
              ,SI.CORRESPONDENT_ACCOUNT as correspondentBankAccount
              ,SI.CORRESPONDENT_ABA as correspondentBankAbaNum
              ,SI.CORRESPONDENT_SORT_CODE as correspondentBankSortCode
              ,SI.BENEFICIARY_NAME as beneficiaryName
              ,SI.BENEFICIARY_CODE as beneficiarySwiftCode
              ,SI.BENEFICIARY_ACCOUNT as beneficiaryAccount
              ,SI.BENEFICIARY_IBAN as beneficiaryIban
              ,SI.STATUS as status
              ,case
                 when exists (select 1
                       from   login_profile
                       where  profilename = SI.SUBMIT_BY
                       and    superadmin = 1) then
                  (select ul.FIRSTNAME || ' ' || ul.LASTNAME || ' (Markit)'
                   from   user_login ul
                   where  ul.loginName = SI.SUBMIT_BY)
                 else
                  (select ul.FIRSTNAME || ' ' || ul.LASTNAME
                   from   user_login ul
                   where  ul.loginName = SI.SUBMIT_BY)
               end as submitBy
              ,SI.SUBMIT_DATE as submitDate
              ,SI.ACTION_BY as approvedRejectedBy
              ,SI.ACTION_DATE as approvedRejectedDate
              ,case
                 when EVENT_TYPE is not null then
                  (select LISTAGG(ET.LOOKUP_VALUE, ', ') WITHIN group(order by ET.DISPLAY_SEQ)
                   from   LU_SSI_EVENT_TYPE ET
                         ,SSI_EVENT_TYPE    SE
                   where  ET.SSI_EVENT_TYPE = SE.EVENT_TYPE
                   and    SE.SSI_REFERENCE_ID = SI.SSI_REFERENCE_ID)
                 else
                  (select LISTAGG(LOOKUP_VALUE, ', ') WITHIN group(order by DISPLAY_SEQ) from LU_SSI_EVENT_TYPE)
               end as eventType
              ,SI.party_id as partyId
              ,p.party_mei as partyMei
              ,NVL2(SI.TRADE_TYPE
                   ,(select T.LOOKUP_VALUE from LU_TRADE_TYPE T where T.TRADE_TYPE = SI.TRADE_TYPE)
                   ,(select LISTAGG(LOOKUP_VALUE, ', ') WITHIN group(order by DISPLAY_SEQ) from LU_TRADE_TYPE)) as tradeType
              ,NVL2(SI.DOCUMENT_TYPE
                   ,(select D.LOOKUP_VALUE
                    from   LU_LOAN_DOCUMENT_TYPE D
                    where  D.LOAN_DOCUMENT_TYPE = SI.DOCUMENT_TYPE)
                   ,(select LISTAGG(LOOKUP_VALUE, ', ') WITHIN group(order by DISPLAY_SEQ)
                    from   LU_LOAN_DOCUMENT_TYPE)) as documentType
              ,SI.REV_ID as revisionNumber
              ,mc_dcl.get_ssi_action(SI.status) as actionList
              ,case
                 when exists (select 1
                       from   login_profile
                       where  profilename = SI.SUBMIT_BY
                       and    profile_id = p_profileId) then
                  1
                 else
                  0
               end as isSubmitUser
        from   SETTLEMENT_INSTRUCTION SI
        left   join party p on (p.party_id = SI.party_id)
        where  SI.party_id = p_partyId
        and    (p_status is null or SI.status = p_status)
        order  by SI.SSI_REFERENCE_ID
                 ,case
                    when p_sortByCcy is not null then
                     SI.CURRENCY
                  end desc;
  end getPartySSIListByMei;