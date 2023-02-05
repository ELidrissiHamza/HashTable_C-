/**Dans ce code, nous avons d�fini une classe HashMap
pour impl�menter la table de hachage. La classe contient
un vecteur table de listes de paires de cl�s et de valeurs,
o� chaque liste repr�sente une case de la table.
La m�thode hashFunction calcule l'index dans le vecteur
table pour un ensemble donn� de donn�es en utilisant
la cl� comme entr�e. La m�thode insert ajoute une paire
cl�-valeur � la liste correspondante, tandis que
la m�thode search recherche la valeur correspondante � la cl� donn�e.**/


#include <iostream>
#include <vector>
#include <list>
#include <utility>

const int TABLE_SIZE = 200;

class HashMap {
  private:
    std::vector<std::list<std::pair<int, int>>> table;

  public:
    HashMap() : table(TABLE_SIZE) {}

    int hashFunction(int key) {
      return key % TABLE_SIZE;
    }

    void insert(int key, int value) {
      int index = hashFunction(key);
      table[index].push_back({key, value});
    }

    int search(int key) {
      int index = hashFunction(key);
      for (const auto &pair : table[index]) {
        if (pair.first == key) {
          return pair.second;
        }
      }
      return -1;
    }
};

int main() {
  HashMap hashMap;
  hashMap.insert(1, 10);
  hashMap.insert(2, 250);
  hashMap.insert(3, 330);
  std::cout << hashMap.search(1) << std::endl;
  return 0;
}
