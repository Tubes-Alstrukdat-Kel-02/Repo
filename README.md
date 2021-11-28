# Tubes-AlStrukDat

## Deskripsi Singkat
Program Mobitangga adalah permainan berbasis command-line interface (CLI) yang menggabungkan game ular tangga dengan modifikasi-modifikasi tambahan. Modifikasi dari ular tangga biasa ini ditunjukan dengan adanya fitur yaitu skill beserta buff yang beragam dengan keunggulannya masing-masing yang juga bervariasi.

## Panduan Gameplay
Demo dapat dilihat [disini](https://replit.com/@18219076Yahya/Repo)

  1. Game dimulai
  2. Inisialisasi player queue, setiap player dimasukkan ke dalam satu queue. Co: 1, 2, 3, 4
     - Setiap nomor menandakan satu orang player
     - playerLocation[i] untuk lokasi player i+1 dst
     - playerName[i] untuk nama player i+1 dst
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

## Identitas Anggota Kelompok
- Yahya Aqrom............(18219076)	 
- Joanna Margareth Nauli.(18220007)
- Joshi Ryu Setiady......(18220025)
- Rachmad Hidayat........(18220049)
- Alya Apriliyanti.......(18220050)
- Ahmad Wafika Samsea....(18220088)

## Cara Compile
- Di linux: 
  - Pastikan sudah menginstall gcc / mingw versi terbaru
  - Masuk ke dalam terminal/shell
  - Ketik "gcc main.c src/*/*.c -o linuxPlay" di shell
  - Untuk mengeksekusi program, ketik "./linuxPlay" di shell
- Di windows:
  - Pastikan sudah menginstall gcc / mingw versi terbaru
  - Masuk ke dalam terminal/shell
  - Ketik "gcc main.c src/ADT/array.c src/ADT/listlinier_skill.c src/ADT/mesin_kar.c src/ADT/mesin_kata.c src/ADT/queueRenamed.c src/Func/stack.c src/Func/buff.c src/Func/gameplay.c src/Func/inspect.c src/Func/map.c src/Func/roll.c src/Func/SaveLoad.c src/Func/skill.c src/Func/undo.c -o winPlay.exe"
    - Tambahkan file .c yang lain jika belum ada di command di atas 
  - Untuk mengeksekusi program, klik dua kali program tersebut
