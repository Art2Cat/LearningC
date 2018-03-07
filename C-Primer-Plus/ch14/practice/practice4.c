#include <stdio.h>
#include <string.h>

#define LEN 5

struct insured {
  char fName[10];
  char mName[10];
  char lName[10];
};

struct siprofile {
  int siId;
  struct insured insuredP;
};

void printProfiles(const struct siprofile *, int len);

int main(int argc, char **argv) {
  struct siprofile insureds[LEN] = {
      {111110, {"Ming", "Yi", "Huang"}}, {111111, {"Ming", "Yi", "Huang"}},
      {111112, {"YiMing", "", "Huang"}}, {111113, {"Ming", "", "Huang"}},
      {111114, {"Ming", "Yi", "Huang"}},
  };
  printProfiles(insureds, LEN);
  return 0;
}

void printProfile(const struct siprofile *profile);

void printProfiles(const struct siprofile *profiles, int len) {
  struct siprofile profile;
  for (int i = 0; i < len; i++) {
    profile = profiles[i];
    printProfile(&profile);
  }
}

void printProfile(const struct siprofile *profile) {
  struct insured insuredp;
  insuredp = profile->insuredP;
  if (strcmp(insuredp.mName, "") != 0) {
    printf("%s, %s %c. -- %d\n", insuredp.fName, insuredp.lName,
           insuredp.mName[0], profile->siId);
  } else {
    printf("%s, %s -- %d\n", insuredp.fName, insuredp.lName, profile->siId);
  }
}