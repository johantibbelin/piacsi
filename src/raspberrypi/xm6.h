//---------------------------------------------------------------------------
//
//	SCSI Target Emulator RaSCSI (*^..^*)
//	for Raspberry Pi
//
//	Powered by XM6 TypeG Technology.
//	Copyright (C) 2016-2020 GIMONS
//
//	[ 共通定義 ]
//
//---------------------------------------------------------------------------

#if !defined(xm6_h)
#define xm6_h

//---------------------------------------------------------------------------
//
//	VERSION
//
//---------------------------------------------------------------------------
#define VERSION 0x0147

//---------------------------------------------------------------------------
//
//	RaSCSI
//
//---------------------------------------------------------------------------
#define RASCSI VERSION

//---------------------------------------------------------------------------
//
//	IDマクロ
//
//---------------------------------------------------------------------------
#define MAKEID(a, b, c, d)	((DWORD)((a<<24) | (b<<16) | (c<<8) | d))

//---------------------------------------------------------------------------
//
//	各種動作設定
//
//---------------------------------------------------------------------------
#define USE_SEL_EVENT_ENABLE			// SEL信号をイベントでチェックする
#define REMOVE_FIXED_SASIHD_SIZE		// SASIHDのサイズ制限を解除する
#define USE_MZ1F23_1024_SUPPORT			// MZ-1F23(SASI 20M/セクタサイズ1024)

//---------------------------------------------------------------------------
//
//	クラス宣言
//
//---------------------------------------------------------------------------
class Fileio;
										// ファイル入出力
class Disk;
										// SASI/SCSIディスク
class Filepath;
										// ファイルパス

#endif	// xm6_h