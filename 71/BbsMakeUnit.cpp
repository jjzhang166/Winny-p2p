//---------------------------------------------------------------------------
#include "hdrs.h"

#include <vcl.h>
#pragma hdrstop

#include "def.h"

#include "MainUnit.h"
#include "BbsMakeUnit.h"

#include "def2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBbsMakeForm *BbsMakeForm;
//---------------------------------------------------------------------------

__fastcall TBbsMakeForm::TBbsMakeForm(TComponent * Owner)
        : TForm(Owner)
{
	FILE * local_00;
	char local_01[1024];
	sprintf(local_01,"%s%s",/*(const char *)*/g_AppPath,"BoardList.txt");
	local_00=fopen(local_01,"rt");
	if (local_00!=0) {
		fclose(local_00);
		BoardListCombo->Items->LoadFromFile(local_01);
	}
	else {
	ny_addlog("*BBS���ރt�@�C���̓ǂݍ��ݎ��s");
	}
}


void __fastcall TBbsMakeForm::Button1Click(TObject * Sender)
{
	Close();
	return;
}



//ansistring�t�߂̃��[�J���A�T�C������B�悭�킩���
void __fastcall TBbsMakeForm::OkButtonClick(TObject * Sender)
{
	char local_10[4096];
	char local_11[4096];
	char local_12[256];

	if (g_pCMainControl->m_optflag_notConnected__) {
		MessageBox(Handle,"�O������ڑ��ł��Ȃ��m�[�h�iPort0�j�̓X���b�h�����Ă��܂���","Winny",0x00042030);
	}
	else
	if (g_pCMainControl->mf_CMainControl_1470()>=100) {
		sprintf(local_12,"�X���b�h��1�m�[�h��%d�܂ł������܂���",100);
		MessageBox(Handle,local_12,"Winny",0x00042030);
	}
	else
	if ( TitleEdit->Text.Length()<4||TitleEdit->Text.Length()>=240 ) {
		MessageBox(Handle,"�X���b�h���͔��p��4�����ȏ�ɂ��Ă�������","Winny",0x00042030);
	}
	else
	if (TitleEdit->Text.Pos(":")>0) {
		MessageBox(Handle,"�X���b�h����\":\"�͎g���܂���","Winny",0x00042030);
	}
	else
	if (TripCombo->Text.Length()<1) {
		MessageBox(Handle,"�g���b�v����������͕K���w�肵�Ă�������","Winny",0x00042030);
	} else {

//!!475557�t�� ���̂ق���ansistring local_01�̈����ɂ��A���̂ւ񂪃Y���Ă���͗l�B���C�u�����̃C�����C���W�J���H
		sprintf(local_11,"[BBS_%s] %s",/*(const char *)*/BoardListCombo->Text,/*(const char *)*/TitleEdit->Text);
		sprintf(local_10,"%s\\%s",g_pCMainControl->m_sz_BbsFolderPath_,local_11);
		FILE * local_03;
		local_03=fopen(local_10,"r");
		if (local_03!=0) {
			fclose(local_03);
			MessageBox(Handle,"����BBS�t�@�C�������݂��܂�","Winny",0x00042030);
			goto ret;	//return;
		}
		FILE * local_04;
		local_04=fopen(local_10,"wt");
		if (local_04!=0) {
			fprintf(local_04,"%s%s\n","WinnyBBS 2.0b1 ",TripCombo->Text.c_str());
			fclose(local_04);
			g_pCMainControl->mf_CMainControl_1550();
		} else {
			MessageBox(Handle,"BBS�t�@�C���̍쐬�Ɏ��s���܂���","Winny",0x00042030);
			return;
		}


		AnsiString local_01=(TripCombo->Text);
		int	local_05=0;
		if (local_01.Length()>=2) {
			int local_06;
			int local_07;
			bool local_08;

			local_06=TripCombo->Items->Count;
			local_07=0;
			local_08=false;
			for (int local_09=0; local_09<local_06; local_09++) {
				AnsiString local_02=(TripCombo->Items->Strings[local_09]);
				if (local_02.AnsiCompare(local_01)==0) {
					local_08=true;
					local_07=local_09;
					break;
				}
			}
			if (!local_08) {
				TripCombo->Items->Insert(local_07,local_01);
				local_05=local_05+1;
			}
		}

		if (g_AppPath.Length()!=0) {
			sprintf(local_10,"%s%s",/*(const char *)*/g_AppPath,"BbsTripString.txt");
			try {
				TripCombo->Items->SaveToFile(local_10);
			}
			catch (const EFOpenError & ex_116) {
			}
		}
		MainForm->TabControlChange(NULLPO);
		Close();
	}
ret:	;
}


//---------------------------------------------------------------------------
