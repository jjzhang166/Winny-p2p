//---------------------------------------------------------------------------

#ifndef BbsMakeUnitH
#define BbsMakeUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TBbsMakeForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
	TComboBox *                    BoardListCombo                ;   //fr    752      4 
	TLabel *                       Label1                        ;   //fr    756      4 
	TLabel *                       Label2                        ;   //fr    760      4 
	TEdit *                        TitleEdit                     ;   //fr    764      4 
	TLabel *                       Label3                        ;   //fr    768      4 
	TButton *                      OkButton                      ;   //fr    772      4 
	TButton *                      Button1                       ;   //fr    776      4 
	TComboBox *                    TripCombo                     ;   //fr    780      4 
	void __fastcall Button1Click(TObject * Sender);
	void __fastcall OkButtonClick(TObject * Sender);

private:	// ���[�U�[�錾
public:		// ���[�U�[�錾
	__fastcall TBbsMakeForm(TComponent * Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBbsMakeForm *BbsMakeForm;
//---------------------------------------------------------------------------
#endif
