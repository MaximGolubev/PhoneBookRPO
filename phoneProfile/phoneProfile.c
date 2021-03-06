#include "phoneProfile.h"
#include <stdio.h>


phoneUserLabel* buildPhoneProfile(const char* name,
                                  const char* phone) {
    phoneUserLabel* label = (phoneUserLabel*)malloc(sizeof(phoneUserLabel));
    label->name = (char*)malloc(strlen(name) * sizeof(char));
    label->phone = (char*)malloc(strlen(phone) * sizeof(char));
    for (int i = 0; i < strlen(name); ++i) {
        label->name[i] = name[i];
    }
    for (int i = 0; i < strlen(phone); i++) {
        label->phone[i] = phone[i];
    }
    return label;
}

void printPhoneProfile(phoneUserLabel* label){
    printf("=======================\n");
    printf("Имя - %s\n", label->name);
    printf("Телефон - %s\n", label->phone);
    printf("=======================\n");
}

void freePhoneProfile(phoneUserLabel* label){
    free(label->name);
    free(label->phone);
    free(label);
}

char *formatToFile(phoneUserLabel* label){
    char *result = (char*)malloc((strlen(label->name)+strlen(label->phone))  * sizeof(char));
    strcpy(result, label->name);
    result = strcat("|", result);
    result = strcat(label->phone, result);
    return result;
}