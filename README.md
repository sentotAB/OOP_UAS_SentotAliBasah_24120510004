# FC Cakrawala — UAS OOP 2025

## Deskripsi Proyek

Ini adalah proyek sederhana untuk implementasi konsep Object-Oriented Programming (OOP) menggunakan bahasa C++.

FC Cakrawala merupakan klub sepak bola binaan Universitas Cakrawala. Dalam proyek ini, saya membuat satu tim kelompok umur U-23 bernama **FC Cakrawala Muda**, yang memiliki:
- 1 Head Coach
- 1 Assistant Coach
- 15 pemain mahasiswa

Struktur program dibuat berdasarkan diagram UML yang diberikan.

---

## Struktur Kelas

Program terdiri dari beberapa class:
- `Person`: kelas dasar untuk semua orang (pelatih, pemain, staf)
- `Player`: kelas turunan dari `Person`
- `Coach`: kelas turunan dari `Person`
- `Team`: menyimpan daftar pemain dan pelatih

---

## Metode Factory

Saya menggunakan pendekatan **Factory Method Pattern** untuk membuat objek. Hal ini menjaga fleksibilitas dan struktur OOP tetap sesuai prinsip desain:
- `PlayerFactory` untuk membuat pemain
- `CoachFactory` untuk membuat pelatih
- Semua objek disimpan sebagai `Person` melalui polimorfisme

---

## Cara Menjalankan

1. Kompilasi program dengan g++:
   ```bash
   g++ OOP_UAS1_SentotAliBasah_24120510004.cpp -std=c++17 -o OOP_UAS1_SentotAliBasah_24120510004.exe

