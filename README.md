# Tubes-AlStrukDat

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


## Cara Compile
- Di linux: 
  - Masuk ke dalam shell (apapun)
  - Ketik "gcc main.c src/*/*.c -o play" di shell
  - Untuk mengeksekusi program, ketik "./play" di shell
- Di windows:
  - Masuk ke dalam shell (apapun)
  - Ketik "gcc main.c src/ADT/queueRenamed.c src/Func/gameplay.c src/Func/roll.c -o play.exe"
  - Untuk mengeksekusi program, klik dua kali program tersebut