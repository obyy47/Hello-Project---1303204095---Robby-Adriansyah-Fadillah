#ifndef EDUKASI_H_INCLUDED
#define EDUKASI_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define pegawai(P) P->pegawai
#define riwayatP(P) P->riwayatP
#define prev(P) P->prev
#define info(P) P->info
#define last(L) L.last

struct infotype_riwayatP{
    string namaRP; // Nama Pendidikan
    int tahunRP; // Tahun pendidikan
    string kotaRP; // Kota Pendidikan
    string jenisRP; // Jenis Pendidikan (Formal atau Non-Formal) = Dijadikan relasi
};

struct infotype_pegawai{
     string jenisPW; // Riwayat Pedidikan Pegawai (Formal atau Non-Formal) = Dijadikan relasi
     string namaPW; // Nama Pegawai
     int teleponPW; // Telepon Pegawai
     string agamaPW; // Agama Pegawai
};

typedef infotype_riwayatP riwayatP;
typedef infotype_pegawai pegawai;
typedef struct elm_pegawai *adr_pegawai;
typedef struct elm_riwayatP *adr_riwayatP;
typedef struct elm_relasi *adr_relasi;

struct list_pegawai{
    adr_pegawai first;
    adr_pegawai last;
};

struct list_riwayatP{
    adr_riwayatP first;
};

struct list_relasi{
    adr_relasi first;
    adr_relasi last;
};

struct elm_pegawai{
    infotype_pegawai info;
    adr_pegawai next;
};

struct elm_riwayatP{
    infotype_riwayatP info;
    adr_riwayatP next;
};

struct elm_relasi{
    adr_pegawai pegawai;
    adr_riwayatP riwayatP;
    adr_relasi next;
    adr_relasi prev;
};

void createListriwayatP(list_riwayatP &d);
adr_riwayatP createElmriwayatP(riwayatP riwayatP);
void createListpegawai(list_pegawai &m);
adr_pegawai createElmpegawai(pegawai pegawai);
void createListrelasi(list_relasi &r);
adr_relasi createELmrelasi();

adr_pegawai searchpegawai(list_pegawai m, pegawai pegawai);
adr_pegawai searchpegawai2(list_relasi m, pegawai pegawai);


void insertpegawai(list_pegawai &m, adr_pegawai p);
void insertriwayatP(list_riwayatP &d, adr_riwayatP q);

void findPegawai(list_pegawai m);
void insertRelasi(list_pegawai m, list_riwayatP d, list_relasi &r, riwayatP riwayatP, pegawai pegawai);

void caripegawaiRelasi(list_relasi r, list_riwayatP d);

void deleteAfterRelasi(list_relasi &r, adr_relasi p);
void deleteriwayatP(list_riwayatP &d, list_relasi &r, riwayatP riwayatP);
void deleteAfterriwayatP(list_riwayatP &d, adr_riwayatP p);
void deleteAfterpegawai(list_pegawai &m, adr_pegawai p);
void deletepegawai(list_pegawai &m, list_relasi &r, pegawai pegawai,riwayatP riwayatP);
int menuEdukasi();
void Tampilan();
void viewNotRelation(list_riwayatP d, list_pegawai m);
void viewRelation(list_riwayatP d, list_relasi r);

void countriwayatP(list_pegawai m,list_relasi r, pegawai pegawai, list_riwayatP d, riwayatP riwayatP);
void countPegawai(list_pegawai m,list_relasi r, pegawai pegawai, list_riwayatP d, riwayatP riwayatP);

#endif // EDUKASI_H_INCLUDED
