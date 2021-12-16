//Zachary Keffaber, 2021/11/5, ButtermilkParamParser

#include <stdio.h>
#include <string.h>

char *butterparam(char *line, int type) {
  char *returnkey;
  int c = 0;
  int charindex = 0;
  int charindex2 = 0;
  int charindex3 = 0;
  int tempint = 0;
  int instring = 0;
 
  //fp=fopen("testwrite.txt", "w");
  //fprintf(fp, "aba");
  //fclose(fp);
    charindex = 0;
    charindex2 = 0;
    tempint = 0;
    c = 0;
    while (tempint == 0){
      if (line[charindex] == '('){
        tempint++;
      }
      charindex++;
    }
    tempint = 0;
    while (charindex+tempint<strlen(line)){
      if (line[charindex+tempint] == ')'){
        charindex2 = tempint;
      }
      tempint++;
    }
    tempint = 0;
    if (charindex+1==charindex2){
      return 0;
    }
    char params[charindex2];
    char value[charindex2];
    memcpy(params,&line[charindex],charindex2);
    params[charindex2] = '\0';
    //value[c] = '\0';
    charindex = 0;
    charindex2 = 1;
    charindex3 = 0;
    c = 0;
    instring = 0;
    for(int i = 0; i < strlen(params); ++i) {
      if (params[i] == '\"' && (!(params[i-1] == '\\'))){
        if (instring == 1) {
          instring = 0;
        } else {
          instring = 1;
        }
      }
      if (instring == 0 && params[i] == '=' && (!(params[i-1] == '\\'))){
        while (params[i-charindex] == ' ' && i-charindex > 0){
          charindex++;
        }
        while (params[i+charindex2] == ' ' && i+charindex2 < strlen(params)){
          charindex2++;
        }
        while ((!(params[i+charindex2+charindex3] == ',')) && i+charindex2+charindex3 < strlen(params)){
          charindex3++;
        }
        while (c < charindex3) {
            value[c] = params[i+charindex2+c];
            c++;
        }
        value[charindex3] = '\0';
        /*
        memcpy(value,&line[i+charindex2],strlen(line)-i+charindex2+charindex3);
        value[strlen(line)-i+charindex2+charindex3] = '\0';
        */
        params[i-charindex-1] = '\0';
        //v
      }
    }
    if (type == 0){ //type 0 is parameter, 1 is value
      printf("\n\n%s",params);
      returnkey = params;
      return returnkey;
    } else {
      printf("\n\n%s",value);
      returnkey = value;
      return returnkey;
    }
    return 0;
}
