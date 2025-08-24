/* THE FOLLOWING PROGRAMME DEMONSTRATES A PLAYLIST MANAGEMENT SOFTWARE.
USERS ARE ABLE TO FILL IN DETAILS OF THE SONGS , ADD OR REMOVE SONGS AS PER THEIR CHOICE AND MODIFY THE TITLE AS AND WHEN NEEDED.
PURPOSE OF THE PROGRAMME IS NOT TO SIMULATE A REAL-WORLD USER-INTERACTION, RATHER TO EXPLORE THE FOLLOWING CONCEPTS AND THEIR USAGE:
1. ACCESS SPECIFIERS
2. CONSTRUCTOR TYPES
3. DEEP COPY AND SHALLOW COPY
4. DYNAMIC MEMORY ALLOCATION FOR ATTRIBUTES AND CLASSES */

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class song {
private:
    char* artist;
    char* album;

public:
    char* title;

    // DEFAULT CONSTRUCTOR
    song() {
        cin.ignore(); // flush buffer before getline
        title = new char[50];
        cout << "Enter the title of the song: ";
        cin.getline(title, 50);

        artist = new char[50];
        cout << "Enter the artist of the song: ";
        cin.getline(artist, 50);

        album = new char[50];
        cout << "Enter the album of the song: ";
        cin.getline(album, 50);
    }

    // PARAMETERIZED CONSTRUCTOR
    song(const char* title, const char* artist, const char* album) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);

        this->artist = new char[strlen(artist) + 1];
        strcpy(this->artist, artist);

        this->album = new char[strlen(album) + 1];
        strcpy(this->album, album);
    }

    // DEEP COPY CONSTRUCTOR
    song(const song& other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);

        artist = new char[strlen(other.artist) + 1];
        strcpy(artist, other.artist);

        album = new char[strlen(other.album) + 1];
        strcpy(album, other.album);
    }

    // MODIFY FUNCTION
    void modify() {
        cin.ignore(); // flush buffer before getline
        delete[] title;
        title = new char[50];
        cout << "Enter the new title of the song: ";
        cin.getline(title, 50);

        delete[] artist;
        artist = new char[50];
        cout << "Enter the new artist of the song: ";
        cin.getline(artist, 50);

        delete[] album;
        album = new char[50];
        cout << "Enter the new album of the song: ";
        cin.getline(album, 50);

        cout << "The song details now are:\nTitle: " << title
             << "\nArtist: " << artist
             << "\nAlbum: " << album << endl;
    }

    // DESTRUCTOR
    ~song() {
        delete[] title;
        delete[] artist;
        delete[] album;
    }

    // DISPLAY FUNCTION
    void display() const {
        cout << "Title: " << title << ", Artist: " << artist << ", Album: " << album << endl;
    }
};

// ADD SONG TO PLAYLIST
void playlist_expand(vector<song>& playlist, const song& other) {
    playlist.push_back(other);
}

// REMOVE SONG FROM PLAYLIST
void remove_song(vector<song>& playlist) {
    cin.ignore(); // flush buffer before getline
    cout << "Enter the title of the song to remove: ";
    char searchtitle[50];
    cin.getline(searchtitle, 50);

    for (size_t i = 0; i < playlist.size(); i++) {
        if (strcmp(playlist[i].title, searchtitle) == 0) {
            playlist.erase(playlist.begin() + i);
            cout << "Song removed from playlist.\n";
            return;
        }
    }
    cout << "Song not found.\n";
}

int main() {
    vector<song> playlist;
    int choice;
    do {
        cout << "\nWELCOME TO A CHEAPER VERSION OF SPOTIFY. NO ADS I PROMISE. HERE ARE THE ACTIONS:\n";
        cout << "1. Add Song to the playlist\n";
        cout << "2. Remove a Song from the playlist\n";
        cout << "3. Modify a Song from the playlist\n";
        cout << "4. Display Playlist\n";
        cout << "5. Demonstrate Deep Copy\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            song s;
            playlist_expand(playlist, s);
            cout << "Song added to playlist.\n";
        }
        else if (choice == 2) {
            if (playlist.empty()) {
                cout << "Playlist is empty.\n";
            } else {
                remove_song(playlist);
            }
        }
        else if (choice == 3) {
            if (playlist.empty()) {
                cout << "Playlist is empty.\n";
                continue;
            }
            int idx;
            cout << "Enter song index to modify (starting from 1): ";
            cin >> idx;
            if (idx < 1 || idx > playlist.size()) {
                cout << "Invalid index.\n";
            } else {
                playlist[idx - 1].modify();
            }
        }
        else if (choice == 4) {
            if (playlist.empty()) {
                cout << "Playlist is empty.\n";
            } else {
                cout << "\n--- Playlist ---\n";
                for (size_t i = 0; i < playlist.size(); ++i) {
                    cout << i + 1 << ". ";
                    playlist[i].display();
                }
            }
        }
        else if (choice == 5) {
            if (playlist.empty()) {
                cout << "Add at least one song first.\n";
            } else {
                cout << "Demonstrating deep copy:\n";
                song copySong = playlist[0]; // invokes deep copy
                cout << "Original song: ";
                playlist[0].display();
                cout << "Copied song: ";
                copySong.display();
                cout << "Now modifying original song...\n";
                playlist[0].modify();
                cout << "\nOriginal song after modification: ";
                playlist[0].display();
                cout << "Copied song remains: ";
                copySong.display();
            }
        }
    } while (choice != 0);

    cout << "Exiting Playlist Manager.\n";
    return 0;
}
