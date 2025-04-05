Music Playlist Manager
This is a C program that manages a music playlist using a circular linked list. The program allows users to add, delete, display, and manipulate songs in the playlist. It supports various features such as shuffling, counting songs, searching, and clearing the entire playlist.

Features
Add Song(s): Allows you to add multiple songs to the playlist.

Delete Song: Allows you to remove a song from the playlist by its name.

Display Playlist: Displays the list of songs currently in the playlist.

Play Next Song: Plays the next song in the playlist.

Current Song: Displays the song that is currently playing.

Count Songs: Displays the total number of songs in the playlist.

Search Song: Searches for a song by its name in the playlist.

Shuffle Play: Randomly selects a song from the playlist and plays it.

Clear Playlist: Deletes all songs from the playlist.

Exit: Exits the program, cleaning up resources.

Table of Contents
Compilation and Execution

Program Functions

Sample Output

How to Use

License

Compilation and Execution
Prerequisites
Ensure you have a C compiler (like GCC) installed on your system.

Compilation Command
bash
Copy
gcc -o playlist_manager playlist_manager.c
Execution Command
bash
Copy
./playlist_manager
Program Functions
1. addSong(char* songName)
This function adds a song to the playlist. If the playlist is empty, the song is added as the first node and points to itself. If the playlist is not empty, the song is added at the end, and the pointer is updated to reflect the new last node.

2. deleteSong(char* songName)
This function removes a song from the playlist. It searches for the song and deletes it. If there is only one song in the playlist, it empties the playlist. It also handles updating the last pointer if the deleted song is the last song.

3. displayPlaylist()
This function displays the entire playlist, showing each song in the order they appear in the circular linked list.

4. playNext(Node** current)
This function plays the next song in the playlist by moving the current pointer to the next song. If the playlist is empty, it notifies the user.

5. currentSong(Node* current)
This function displays the song that is currently being played.

6. countSongs()
This function counts the total number of songs in the playlist and displays the result.

7. searchSong(char* name)
This function searches for a specific song by its name and prints the position if found. If the song is not found, it notifies the user.

8. shufflePlay(Node** current)
This function selects a random song from the playlist and plays it. It shuffles the list by generating a random index and moves the current pointer to the selected song.

9. clearPlaylist()
This function deletes all songs in the playlist and frees the memory used by each node.

10. main()
The main function runs an interactive menu where users can choose different actions for managing the playlist. The program runs until the user chooses to exit, at which point it clears the playlist and exits.

Sample Output
bash
Copy
Music Playlist Manager
1. Add Song(s)
2. Delete Song
3. Display Playlist
4. Play Next Song
5. Current Song
6. Count Songs
7. Search Song
8. Shuffle Play
9. Clear Playlist
10. Exit
Enter your choice: 1
How many songs do you want to add? 2
Enter song 1 name: Song 1
Added: Song 1
Enter song 2 name: Song 2
Added: Song 2

Music Playlist Manager
1. Add Song(s)
2. Delete Song
3. Display Playlist
4. Play Next Song
5. Current Song
6. Count Songs
7. Search Song
8. Shuffle Play
9. Clear Playlist
10. Exit
Enter your choice: 3

Playlist:
 - Song 1
 - Song 2
How to Use
Run the program.

Choose the desired action from the menu (e.g., Add Song, Delete Song, etc.).

Follow the prompts for each action.

Use the Exit option to terminate the program.