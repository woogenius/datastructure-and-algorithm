//
//  HW4.1.C3
//  WooGenius
//  13.10.20
//

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct humanBeing {
    char name[10];
    int age;
    float salary;
} humanBeing_t;

int humansEqualByValue(humanBeing_t person1, humanBeing_t person2);
int humansEqualByReference(humanBeing_t *person1, humanBeing_t *person2);

int main(void) {
    humanBeing_t person1, person2;

    person1.age = 25;
    strcpy(person1.name, "WooGenius");
    person1.salary = 1000000;
    
    person2.age = 28;
    strcpy(person1.name, "TaekSoon");
    person2.salary = 2000000;
    
    printf("%d\n",humansEqualByValue(person1, person1));  // 1
    printf("%d\n",humansEqualByValue(person1, person2));  // 0
    printf("%d\n",humansEqualByReference(&person1, &person1));    // 1
    printf("%d\n",humansEqualByReference(&person1, &person2));    // 0
    
    return 0;
}

int humansEqualByValue(humanBeing_t person1, humanBeing_t person2) {
    if (strcmp(person1.name, person2.name))
        return FALSE;
    if (person1.age != person2.age)
        return FALSE;
    if (person1.salary != person2.salary)
        return FALSE;
    
    return TRUE;
}

int humansEqualByReference(humanBeing_t *person1, humanBeing_t *person2) {
    if (strcmp(person1->name, person2->name))
        return FALSE;
    if (person1->age != person2->age)
        return FALSE;
    if (person1->salary != person2->salary)
        return FALSE;
    
    return TRUE;
}
