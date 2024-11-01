//Aliyah Khan
//9/8/2024

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct person {
    int role_index;
    long long total_magic;
};
struct result {
    long long total_magic;
};
struct mag_mat_for_role {
    int type; // index into the list of magical materials
    long long amount_needed;
};

struct role {
    int materials_needed;
    struct mag_mat_for_role* item_list;
};

struct mag_mat_for_list {
    char mat_name[101];
    long long total_amount_needed;
    long long magic_required;
};

//Manage Roles List
typedef struct {
    struct role* array;
    size_t used;
    size_t size;
} roleArray;

void initRoleArray(roleArray* a, size_t initialSize) {
    a->array = (struct role*) malloc(initialSize * sizeof(struct role));
    a->used = 0;
    a->size = initialSize;
}

void insertRoleToArray(roleArray* a, struct role element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (struct role*) realloc(a->array, a->size * sizeof(struct role));
    }
    a->array[a->used++] = element;
}

void freeRoleArray(roleArray* a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

//Manage Role Materials List
typedef struct {
    struct mag_mat_for_role* array;
    size_t used;
    size_t size;
} roleMaterialArray;

void initRoleMaterialArray(roleMaterialArray* a, size_t initialSize) {
    a->array = (struct mag_mat_for_role*)malloc(initialSize * sizeof(struct mag_mat_for_role));
    a->used = 0;
    a->size = initialSize;
}

void insertRoleMaterialToArray(roleMaterialArray* a, struct mag_mat_for_role element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (struct mag_mat_for_role*)realloc(a->array, a->size * sizeof(struct mag_mat_for_role));
    }
    a->array[a->used++] = element;
}

void freeRoleMaterialArray(roleMaterialArray* a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

//Manage Materials List
typedef struct {
    struct mag_mat_for_list* array;
    size_t used;
    size_t size;
} materialArray;

void initMaterialArray(materialArray* a, size_t initialSize) {
    a->array = (struct mag_mat_for_list*)malloc(initialSize * sizeof(struct mag_mat_for_list));
    a->used = 0;
    a->size = initialSize;
}

void insertMaterialToArray(materialArray* a, struct mag_mat_for_list element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (struct mag_mat_for_list*)realloc(a->array, a->size * sizeof(struct mag_mat_for_list));
    }
    a->array[a->used++] = element;
}

void freeMaterialArray(materialArray* a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

//Manage Peoples List
typedef struct {
    struct person* array;
    size_t used;
    size_t size;
} peopleArray;

void initPeopleArray(peopleArray* a, size_t initialSize) {
    a->array = (struct person*)malloc(initialSize * sizeof(struct person));
    a->used = 0;
    a->size = initialSize;
}

void insertPeopleToArray(peopleArray* a, struct person element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (struct person*)realloc(a->array, a->size * sizeof(struct person));
    }
    a->array[a->used++] = element;
}

void freePeopleArray(peopleArray* a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

//Manage results List
typedef struct {
    struct result* array;
    size_t used;
    size_t size;
} resultArray;

void initResultArray(resultArray* a, size_t initialSize) {
    a->array = (struct result*)malloc(initialSize * sizeof(struct result));
    a->used = 0;
    a->size = initialSize;
}

void insertResultToArray(resultArray* a, struct result element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (struct result*)realloc(a->array, a->size * sizeof(struct result));
    }
    a->array[a->used++] = element;
}

void freeResultArray(resultArray* a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}


long long calcTotalMagic(peopleArray* p, roleArray* r, materialArray* m){
    long long totalMagicRequired = 0;
    struct person currentPerson;
    struct mag_mat_for_role currentRoleMaterial;
    for (int k = 0; k < p->used; k++) {
        currentPerson = p->array[k];
        currentPerson.total_magic = 0;
        for (int j=0; j < r->array[currentPerson.role_index].materials_needed; j++){
            currentRoleMaterial = r->array[currentPerson.role_index].item_list[j];
            currentPerson.total_magic += currentRoleMaterial.amount_needed * m->array[currentRoleMaterial.type].magic_required;
        }
        totalMagicRequired += currentPerson.total_magic;
    }
    return totalMagicRequired;
}

void materialUpdate(resultArray* res, peopleArray* p, roleArray* r, materialArray* m){
    char material[101];
    int magicRequired;
    scanf("%s %d", &material, &magicRequired);
    for (int k = 0; k < m->used; k++) {
        if (strcmp(m->array[k].mat_name, material) == 0) {
            m->array[k].magic_required = magicRequired;
            break;
        }
    }
    struct result currentResult;
    currentResult.total_magic = calcTotalMagic(p, r, m);
    insertResultToArray(res, currentResult);
}

void roleUpdate(resultArray* res, peopleArray* p, roleArray* r, materialArray* m){
    char material[101];
    int magicNeeded, roleIndex, materialIndex;
    struct role currentRole;
    scanf("%d %s %d",&roleIndex, &material, &magicNeeded);
    for (int materialIndex = 0; materialIndex < m->used; materialIndex++) {
        if (strcmp(m->array[materialIndex].mat_name, material) == 0) {
            currentRole = r->array[roleIndex-1];\
            for (int k = 0; k < currentRole.materials_needed; k++) {
                if (currentRole.item_list[k].type == materialIndex) {
                    currentRole.item_list[k].amount_needed = magicNeeded;
                    break;
                }
            }
            break;
        }
    }
    struct result currentResult;
    currentResult.total_magic = calcTotalMagic(p, r, m);
    insertResultToArray(res, currentResult);
}

int main()
{
    materialArray myMaterials;
    roleArray myRoles;
    roleMaterialArray myRoleMaterials;
    peopleArray myPeople;
    resultArray myResults;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*&myRoles, n);

        //Setup the material array
        initMaterialArray(&myMaterials, 1);

        //Read in the data for the roles
        for (i = 0; i < n; i++) {
            struct role currentRole;

            //Read in the # of tokens in this line for materials for the current role
            scanf("%d", &numTokens);

            if (numTokens > 0) {
                //Create the list of materials needed for the current role
                initRoleMaterialArray(&myRoleMaterials, numTokens);

                currentRole.item_list = myRoleMaterials.array;
                currentRole.materials_needed = numTokens;

                //Read in the material name and amount needed for the current role
                for (j = 0; j < numTokens; j++) {
                    struct mag_mat_for_list currentMaterial;
                    strcpy(currentMaterial.mat_name,"");
                    currentMaterial.magic_required = 0;
                    currentMaterial.total_amount_needed = 0;

                    struct mag_mat_for_role currentRoleMaterial = { 0 };
                    scanf("%s %d", &material, &materialCount);

                    //If this is the first material that has evern been entered that just put in the material list
                    if (myMaterials.used == 0) {
                        //Set the info for the new material
                        strcpy(currentMaterial.mat_name, material);
                        currentMaterial.total_amount_needed += materialCount;

                        //Add the new material to the material list
                        insertMaterialToArray(&myMaterials, currentMaterial);
                    }
                    else {
                        //if this is not the first material then check to find out if this material is already in list
                        isMaterialNew = true;
                        for (k = 0; k < myMaterials.used; k++) {
                            if (strcmp(myMaterials.array[k].mat_name, material) == 0) {
                                myMaterials.array[k].total_amount_needed += materialCount;
                                isMaterialNew = false;
                                break;
                            }
                        }
                        if (isMaterialNew) {
                            //Set the info for the new material
                            strcpy(currentMaterial.mat_name, material);
                            currentMaterial.total_amount_needed += materialCount;

                            //Add the new material to the material list
                            insertMaterialToArray(&myMaterials, currentMaterial);
                        }
                    }

                    //Set the current roles materials needed
                    currentRoleMaterial.type = myMaterials.used - 1;
                    currentRoleMaterial.amount_needed = materialCount;
                    currentRole.item_list[j] = currentRoleMaterial;

                }

            }
            //Add the current role with its data to my role list
            insertRoleToArray(&myRoles, currentRole);
        }

        //Read in the magic requirements for each Material
        for (k = 0; k < myMaterials.used; k++) {
            scanf("%s %d", &material, &materialCount);

            //Find the material in the material list and update the magic needed
            for (l = 0; l < myMaterials.used; l++) {
                if (strcmp(myMaterials.array[l].mat_name, material) == 0) {
                    myMaterials.array[l].magic_required = materialCount;
                    break;
                }
            }
        }

        //Read in the number of people and then their roles
        scanf("%d", &n);
        c = getchar();

        if (c == '\n') {
            //Set the # of roles
            initPeopleArray(&myPeople, n);

            //Read in the role number for the people
            struct person currentPerson;
            struct mag_mat_for_role currentRoleMaterial;
            for (i = 0; i < n; i++) {
                scanf("%d", &o);
                currentPerson.role_index = o - 1;
                currentPerson.total_magic = 0;
                for (j=0; j < myRoles.array[currentPerson.role_index].materials_needed; j++){
                    currentRoleMaterial = myRoles.array[currentPerson.role_index].item_list[j];
                    currentPerson.total_magic += currentRoleMaterial.amount_needed * myMaterials.array[currentRoleMaterial.type].magic_required;
                }


                //Add this person to my people
                insertPeopleToArray(&myPeople, currentPerson);
            }
        }

    }
    //Read in the number of people and then their roles
    scanf("%d", &n);
    c = getchar();

    if (c == '\n') {
        initResultArray(&myResults, n);
        for (k = 0; k < n; k++){
            scanf("%d", &o);
            if (o == 1){
               materialUpdate(&myResults, &myPeople, &myRoles, &myMaterials);
            }
            else if (o == 2){
                roleUpdate(&myResults, &myPeople, &myRoles, &myMaterials);
            }
        }
    }

    //Debug Print
    //printf("\nOutput\n");
    for (k = 0; k < myResults.used; k++) {
        printf("%d\n", myResults.array[k].total_magic);
    }
    /*
    printf("\nMaterials\n");
    for (k = 0; k < myMaterials.used; k++) {
        printf("%d -> %s Total All Roles Needed: %d Magic Required: %d\n", k, myMaterials.array[k].mat_name, myMaterials.array[k].total_amount_needed, myMaterials.array[k].magic_required);
    }

    printf("\nRoles\n");
    for (k = 0; k < myRoles.used; k++) {
        printf("\n%d -> Role %d -> Total Materials Needed: %d\n", k, k+1, myRoles.array[k].materials_needed);
        printf("\nRole Material List\n");
        for (i = 0; i < myRoles.array[k].materials_needed; i++) {
            printf("Material at Index %d -> this role needs: %d\n", myRoles.array[k].item_list[i].type, myRoles.array[k].item_list[i].amount_needed);
        }

    }

    printf("\nPeople\n");
    for (k = 0; k < myPeople.used; k++) {
        printf("%d -> Is Role #%d which is at Index: %d Magic total: %d\n", k, myPeople.array[k].role_index+1, myPeople.array[k].role_index, myPeople.array[k].total_magic);
    }
    */

    freeRoleArray(&myRoles);
    freeRoleMaterialArray(&myRoleMaterials);
    freeMaterialArray(&myMaterials);
    freePeopleArray(&myPeople);
    freeResultArray(&myResults);
    return 0;
}
