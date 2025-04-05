#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_NAME_LEN 100
typedef struct Node {
    char song[MAX_NAME_LEN];
    struct Node* next;
} Node;
Node* last = NULL;
void addSong(char* songName) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->song, songName);
    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("Added: %s\n", songName);
}

void deleteSong(char* songName) {
    if (last == NULL) {
        printf("Playlist is empty!\n");
        return;
    }

    Node *current = last->next, *prev = last;
    do {
        if (strcmp(current->song, songName) == 0) {
            if (current == last->next && current == last) {
                last = NULL;
            } else {
                prev->next = current->next;
                if (current == last) last = prev;
            }
            free(current);
            printf("Deleted: %s\n", songName);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != last->next);

    printf("Song not found!\n");
}

void displayPlaylist() {
    if (last == NULL) {
        printf("Playlist is empty!\n");
        return;
    }

    Node* temp = last->next;
    printf("\nPlaylist:\n");
    do {
        printf(" - %s\n", temp->song);
        temp = temp->next;
    } while (temp != last->next);
}

void playNext(Node** current) {
    if (*current == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    *current = (*current)->next;
    printf("Now Playing: %s\n", (*current)->song);
}

void currentSong(Node* current) {
    if (current == NULL) {
        printf("No song is currently playing.\n");
        return;
    }
    printf("Currently Playing: %s\n", current->song);
}

void countSongs() {
    if (last == NULL) {
        printf("Playlist is empty!\n");
        return;
    }

    int count = 0;
    Node* temp = last->next;
    do {
        count++;
        temp = temp->next;
    } while (temp != last->next);

    printf("Total number of songs: %d\n", count);
}

void searchSong(char* name) {
    if (last == NULL) {
        printf("Playlist is empty!\n");
        return;
    }

    Node* temp = last->next;
    int pos = 1;
    do {
        if (strcmp(temp->song, name) == 0) {
            printf("Found '%s' at position %d\n", name, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != last->next);

    printf("Song '%s' not found in the playlist.\n", name);
}

void clearPlaylist() {
    if (last == NULL) {
        printf("Playlist is already empty!\n");
        return;
    }

    Node* temp = last->next;
    Node* nextNode;

    while (temp != last) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(last);
    last = NULL;

    printf("All songs have been deleted. Playlist cleared.\n");
}

void shufflePlay(Node** current) {
    if (last == NULL) {
        printf("Playlist is empty!\n");
        return;
    }

    int count = 0;
    Node* temp = last->next;
    do {
        count++;
        temp = temp->next;
    } while (temp != last->next);

    int randomIndex = rand() % count;
    temp = last->next;
    for (int i = 0; i < randomIndex; i++) {
        temp = temp->next;
    }

    *current = temp;
    printf("Shuffled Play: Now Playing: %s\n", temp->song);
}

int main() {
    int choice;
    char songName[MAX_NAME_LEN];
    Node* current = last;

    srand(time(NULL)); 
    do {
        printf("\nMusic Playlist Manager\n");
        printf("1. Add Song(s)\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist\n");
        printf("4. Play Next Song\n");
        printf("5. Current Song\n");
        printf("6. Count Songs\n");
        printf("7. Search Song\n");
        printf("8. Shuffle Play\n");
        printf("9. Clear Playlist\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: {
                int count;
                printf("How many songs do you want to add? ");
                scanf("%d", &count);
                getchar(); 
                for (int i = 0; i < count; i++) {
                    printf("Enter song %d name: ", i + 1);
                    fgets(songName, MAX_NAME_LEN, stdin);
                    songName[strcspn(songName, "\n")] = '\0';
                    addSong(songName);
                }
                if (last != NULL) current = last->next;
                break;
            }
            case 2:
                printf("Enter song name to delete: ");
                fgets(songName, MAX_NAME_LEN, stdin);
                songName[strcspn(songName, "\n")] = '\0';
                deleteSong(songName);
                if (last != NULL) current = last->next;
                break;
            case 3:
                displayPlaylist();
                break;
            case 4:
                playNext(&current);
                break;
            case 5:
                currentSong(current);
                break;
            case 6:
                countSongs();
                break;
            case 7:
                printf("Enter song name to search: ");
                fgets(songName, MAX_NAME_LEN, stdin);
                songName[strcspn(songName, "\n")] = '\0';
                searchSong(songName);
                break;
            case 8:
                shufflePlay(&current);
                break;
            case 9:
                clearPlaylist();
                current = NULL;
                break;
            case 10:
                printf("Exiting...\n");
                clearPlaylist();
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 10);

    return 0;
}

