//---------------------------------------------------------------------------

#ifndef AutoDownUnitH
#define AutoDownUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TAutoDownForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TLabel *                       Label1                        ;
	TLabel *                       Label2                        ;
	TLabel *                       Label3                        ;
	TLabel *                       Label4                        ;
	TLabel *                       Label5                        ;
	TLabel *                       Label6                        ;
	TGroupBox *                    GroupBox1                     ;
	TLabel *                       Label7                        ;
	TLabel *                       Label8                        ;
	TLabel *                       Label9                        ;
	TEdit *                        HashEdit                      ;
	TLabel *                       Label10                       ;
	TEdit *                        UpperSizeEdit                 ;
	TLabel *                       Label11                       ;
	TEdit *                        LowerSizeEdit                 ;
	TCheckBox *                    BbsCheck                      ;
	TCheckBox *                    AutoDeleteCheck               ;
	TGroupBox *                    GroupBox2                     ;
	TCheckBox *                    IgnoreCheck                   ;
	TCheckBox *                    DeleteCheck                   ;
	TCheckBox *                    DisconnectCheck               ;
	TLabel *                       DisconnectLabel               ;
	TButton *                      OkButton                      ;
	TButton *                      CancelButton                  ;
	TComboBox *                    TripCombo                     ;
	TComboBox *                    KeywordCombo                  ;
	TButton *                      ClusterButton                 ;
	void __fastcall CancelButtonClick(TObject * Sender);
	void __fastcall OkButtonClick(TObject * Sender);
	void __fastcall IgnoreCheckClick(TObject * Sender);
	void __fastcall ClusterButtonClick(TObject * Sender);
	void __fastcall FormShow(TObject * Sender);

private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TAutoDownForm(TComponent * Owner);

	int                            m_int1                        ;
	int                            m_int2                        ;
	int                            m_int3_notused                ;
};
//---------------------------------------------------------------------------
extern PACKAGE TAutoDownForm *AutoDownForm;
//---------------------------------------------------------------------------
#endif
