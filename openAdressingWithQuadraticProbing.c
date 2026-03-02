#include <stdio.h>

#define MAX 10

int hash[MAX];

/* ================= INITIALIZATION ================= */
void initialize() {
    for(int i = 0; i < MAX; i++)
        hash[i] = -1;   // -1 means empty
}

/* ================= HASH FUNCTION ================= */
int primaryInd(int key) {
    return key % MAX;
}

/* ================= INSERT ================= */
void insert(int key) {

    int i = 0, ind;

    while(i < MAX) {

        ind = (primaryInd(key) + i*i) % MAX;

        if(hash[ind] == -1 || hash[ind] == -2) {
            hash[ind] = key;
            printf("Key %d inserted at index %d\n", key, ind);
            return;
        }

        printf("Collision occurred at index %d\n", ind);
        i++;
    }

    printf("Hash Table is FULL\n");
}

/* ================= SEARCH ================= */
void search(int key) {

    int i = 0, ind;

    while(i < MAX) {

        ind = (primaryInd(key) + i*i) % MAX;

        if(hash[ind] == -1)
            break;   // key cannot exist beyond this

        if(hash[ind] == key) {
            printf("Key %d found at index %d\n", key, ind);
            return;
        }

        i++;
    }

    printf("Key %d not found\n", key);
}

/* ================= DELETE ================= */
void deleteKey(int key) {

    int i = 0, ind;

    while(i < MAX) {

        ind = (primaryInd(key) + i*i) % MAX;

        if(hash[ind] == -1)
            break;

        if(hash[ind] == key) {
            hash[ind] = -2;   // mark as deleted
            printf("Key %d deleted from index %d\n", key, ind);
            return;
        }

        i++;
    }

    printf("Key %d not found for deletion\n", key);
}

/* ================= DISPLAY ================= */
void display() {

    printf("\nHash Table:\n");

    for(int i = 0; i < MAX; i++) {

        printf("[%d] -> ", i);

        if(hash[i] == -1)
            printf("EMPTY");
        else if(hash[i] == -2)
            printf("DELETED");
        else
            printf("%d", hash[i]);

        printf("\n");
    }
}

/* ================= MAIN ================= */
int main() {

    int choice, key;

    initialize();

    while(1) {

        printf("\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}