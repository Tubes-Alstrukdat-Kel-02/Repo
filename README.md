# Tubes-AlStrukDat

## Panduan Gameplay
Demo dapat dilihat [disini](https://replit.com/@18219076Yahya/Repo)

  1. Game dimulai
  2. Inisialisasi player queue, setiap player dimasukkan ke dalam satu queue. Co: 1, 2, 3, 4
     - Setiap nomor menandakan satu orang player
     - playerLocation[1] untuk lokasi player 1 dst
     - playerName[1] untuk nama player 1 dst
     - Semua konfigurasi untuk tiap player bisa dipanggil berdasarkan  nomor
  3. Ketika ronde dimulai dengan queue 1, 2, 3, 4 artinya giliran player 1, playerTurn jadi 1
     - playerTurn digunakan untuk mempermudah assign ke player yang sedang mendapat giliran
     - Untuk akses playerName menjadi playerName[playerTurn]
     - Untuk akses playerLocation menjadi playerLocation[playerTurn]
     - Dst.
  4. Setelah player melakukan End Turn, queue diubah menjadi 2, 3, 4, 1.
     - Artinya sekarang giliran player 2.
     - playerTurn jadi 2.
  5. Setiap pemain melakukan giliran sampai ronde berganti, yaitu ketika queue kembali ke nomor 1.
     - Skill/buff player direset setiap ronde.
  6. Pemain yang berhasil menuju ke titik akhir / finish line menjadi pemenang.

## ADT
Sebaiknya ADT yang digunakan direname agar penamaan ADT tidak redundan (error). Co: Di ADT Queue ada fungsi IsEmpty() bisa direname jadi IsEmptyQueue() atau Add() bisa direname jadi AddElmtQueue().

### Boolean
 - boolean == unsigned char
 - true == 1
 - false == 0

### Queue
 - Nil == 0
 - HeadQueue(Q)
 - TailQueue(Q)
 - InfoHeadQueue(Q)
 - InfoTailQueue(Q)
 - MaxElQueue(Q)
 - IsEmptyQueue(Queue Q)
 - IsFullQueue (Queue Q)
 - NBElmtQueue (Queue Q)
 - CreateEmptyQueue (Queue * Q, int Max)
 - DeAlokasiQueue (Queue * Q)
 - AddElmtQueue (Queue * Q, infotype X)
 - DelElmtQueue (Queue * Q, infotype * X)
    
## Functionality
### Gameplay
  - initializePlayerQueue()
  - roundLoop()
  - turnLoop()
  - inputCommand()
  - commandSwitchCase()
  - playerWin()

### Roll
 - roll()
 - diceRoll()
 - checkMove()
 - moveOption()
 - movePlayer()

## Notes
 - Map dan Teleporter
    - Map
      - ElType TI berisi nomer petak
      - Contoh : 
          - Map : "....#."
          - maka Array Map : [1,2,3,4,0,6]

      - Jika peta berupa "." maka ElType TI berisi angka bukan nol dan angka merupakan index + 1 
      - Jika peta berupa "#" maka ElType TI berisi angka 0

    - Teleporter
      - petak ke i = index+1
      - Contoh : 
        - Array Teleporter : [2,0,0,6] 
        - Maka index ke 0 yaitu petak ke 1 memiliki teleport dengan petak keluar teleporter di petak ke 2,
        - Index ke 2 yaitu petak ke 3 bukan teleport

      - Jika ElType TI berisi angka 0 maka petak ke-(index+1) tersebut bukan  teleport
      - Jika ElType TI berisi angka selain 0 maka petak ke-(index+1) tersebut merupakan teleport, ElType TI tersebut merupakan petak tujuan dari teleport

## Cara Compile
- Di linux: 
  - Pastikan sudah menginstall gcc / mingw versi terbaru
  - Masuk ke dalam terminal/shell
  - Ketik "gcc main.c src/*/*.c -o linuxPlay" di shell
  - Untuk mengeksekusi program, ketik "./linuxPlay" di shell
- Di windows:
  - Pastikan sudah menginstall gcc / mingw versi terbaru
  - Masuk ke dalam terminal/shell
  - Ketik "gcc main.c src/ADT/queueRenamed.c src/Func/gameplay.c src/Func/roll.c -o winPlay.exe"
    - Tambahkan file .c yang lain jika belum ada di command di atas 
  - Untuk mengeksekusi program, klik dua kali program tersebut
