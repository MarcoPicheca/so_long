## 🇮🇹 ITALIANO

# 🎮 so\_long – 42 School Project

**so\_long** è uno dei primi progetti della Scuola 42 dedicati alla grafica. Lo scopo è creare un semplice videogioco 2D utilizzando la libreria grafica **MiniLibX**, fornita dalla scuola. Il progetto serve per imparare a gestire input da tastiera, disegnare elementi grafici su schermo, e lavorare con strutture dati per la gestione di mappe e movimenti in tempo reale.

---

## 📌 Obiettivo

Creare un gioco in cui un giocatore può muoversi all'interno di una mappa 2D, collezionare oggetti e raggiungere un'uscita, rispettando una serie di vincoli logici e tecnici.

---

## 🧱 Requisiti del gioco

* La mappa è letta da un file `.ber` e rappresentata in formato testuale.
* Deve essere **rettangolare**, **circondata da muri**, e contenere almeno:

  * un punto di partenza (`P`)
  * una o più collezionabili (`C`)
  * un'uscita (`E`)
* Il giocatore può muoversi con i tasti **W, A, S, D**.
* Il gioco termina quando:

  * il giocatore ha raccolto tutti gli oggetti
  * raggiunge l’uscita
* Ogni mossa deve essere **stampata in console** (es. "Moves: 4")

---

## 💻 Tecnologie e vincoli

* Linguaggio: **C**
* Libreria grafica: **MiniLibX** (MLX)
* Nessun uso di librerie esterne o game engine
* Gestione degli **errori** obbligatoria (mappa non valida, file mancante, ecc.)
* Uso corretto della **gestione della memoria** (no leaks)

---

## 🛠️ Compilazione
* `make download`
* `make`
* `./so_long maps/<example>.ber` cambia <example> con una mappa esistente in ./maps
* `make fclean`

## 🇬🇧 English

# 🎮 so\_long – 42 School Project

**so\_long** is one of the first projects at 42 School dedicated to graphics. The goal is to create a simple 2D video game using the **MiniLibX** graphics library provided by the school. The project helps students learn how to handle keyboard input, draw graphical elements on the screen, and work with data structures to manage maps and real-time movement.

---

## 📌 Objective

Create a game where a player can move around a 2D map, collect items, and reach an exit, all while following a series of logical and technical constraints.

---

## 🧱 Game Requirements

* The map is read from a `.ber` file and represented in textual format.
* It must be **rectangular**, **surrounded by walls**, and contain at least:

  * one starting point (`P`)
  * one or more collectibles (`C`)
  * one exit (`E`)
* The player can move using the **W, A, S, D** keys.
* The game ends when:

  * the player has collected all items
  * the player reaches the exit
* Each move must be **printed to the console** (e.g., "Moves: 4")

---

## 💻 Technologies and Constraints

* Language: **C**
* Graphics library: **MiniLibX** (MLX)
* No use of external libraries or game engines
* Mandatory **error handling** (invalid map, missing file, etc.)
* Proper **memory management** (no leaks)

---

## 🛠️ Compilation
* `make download`
* `make`
* `./so_long maps/<example>.ber` change <example> with a map present in ./maps
* `make fclean`

