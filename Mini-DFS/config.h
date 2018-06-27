#pragma once


#define REPLICA_NUM	3

#define FILE_COL	0
#define	DIR_COL		1
#define ID_COL		2
#define CHUNK_COL	4




// Chunk Size: 2M Byte
#define CHUNK_SIZE	2097152

// NameServer Dir
#define NAME_DIR	"NamerServer"
#define DATA_DIR	"DataServer"

// Number of Data Server
#define DATASERVER_NUM	4

#define LISTFILE_NAME	"datalist.txt"


#define ALL_SERVERS	0x0F
#define SERVER_1	0x01
#define SERVER_2	0x02
#define SERVER_3	0x04
#define SERVER_4	0x08