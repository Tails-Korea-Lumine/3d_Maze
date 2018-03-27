#include "MyPG.h"
#include "MyGameMain.h"

//�Q�[�����
TaskFlag			actTask, nextTask; 

//-----------------------------------------------------------------------------
//����������
//�@�\�T�v�F�v���O�����N�����ɂP����s�����i�f�ނȂǂ̏������s���j
//-----------------------------------------------------------------------------
void  MyGameMain_Initalize()
{
	actTask  = Task_Non;	//������Ԃ͎��s���̃^�X�N�𖳌��ɂ��Ă���
	nextTask = Task_Title;	//���̃^�X�N���^�C�g���ɂ��邱�Ƃōŏ��Ƀ^�C�g�������s�����
}
//-----------------------------------------------------------------------------
//�������
//�@�\�T�v�F�v���O�����I�����ɂP����s�����i�f�ނȂǂ̉�����s���j
//-----------------------------------------------------------------------------
void  MyGameMain_Finalize()
{
	DI::GPad_Erase("P1");	//�����I�ɉ���������ꍇ��
}


//-----------------------------------------------------------------------------
//�O���t�@�C�����
namespace  Title {//�^�C�g���^�X�N
	extern  void  Initialize();
	extern  TaskFlag  UpDate();
	extern  void  Render2D();
	extern  void  Render3D();
	extern  void  Finalize();
}
namespace  Game {//�Q�[���{�҃^�X�N
	extern  void  Initialize();
	extern  TaskFlag  UpDate();
	extern  void  Render2D();
	extern  void  Render3D();
	extern  void  Finalize();
}
//�ȉ��K�v�ɉ����Ēǉ�
//-----------------------------------------------------------------------------
//�X�V����
//�@�\�T�v�F�Q�[���̂P�t���[���ɓ����鏈��
//-----------------------------------------------------------------------------
void  MyGameMain_UpDate()
{
	//���Ɏ��s����^�X�N���A���̃^�X�N�ƈ�v���Ȃ�
	if (actTask != nextTask) {
		//�����s���̃^�X�N�̏I���������Ăт���
		switch (actTask) {
		case Task_Title:	Title::Finalize();	break;
		case Task_Game:		Game::Finalize();	break;
			//�ȉ��K�v�ɉ����Ēǉ�
		}
		//���̃^�X�N�Ɉڂ�
		actTask = nextTask;
		//���̃^�X�N�̏������������Ăт���
		switch (actTask) {
		case Task_Title:	Title::Initialize();	break;
		case Task_Game:		Game::Initialize();		break;
			//�ȉ��K�v�ɉ����Ēǉ�
		}
	}
	//���݂̃^�X�N�̎��s�E�X�V�������Ăт���
	switch (actTask) {
	case Task_Title:	nextTask = Title::UpDate();		break;
	case Task_Game:		nextTask = Game::UpDate();		break;
		//�ȉ��K�v�ɉ����Ēǉ�
	}
}
//-----------------------------------------------------------------------------
//�`�揈��
//�@�\�T�v�F�Q�[���̂P�t���[���ɓ�����\������
//-----------------------------------------------------------------------------
void  MyGameMain_Render2D_BF()
{
}
void  MyGameMain_Render2D_AF()
{
	switch (actTask) {
	case Task_Title:	Title::Render2D();	break;
	case Task_Game:		Game::Render2D();	break;
		//�ȉ��K�v�ɉ����Ēǉ�
	}
}
//-----------------------------------------------------------------------------
//�`�揈��
//�@�\�T�v�F�Q�[���̂P�t���[���ɓ�����\������3D
//-----------------------------------------------------------------------------
void  MyGameMain_Render3D_L0()
{
	switch (actTask) {
	case Task_Title:	Title::Render3D();	break;
	case Task_Game:		Game::Render3D();	break;
		//�ȉ��K�v�ɉ����Ēǉ�
	}
}
void  MyGameMain_Render3D_L1()
{
}
void  MyGameMain_Render3D_L2()
{
}
void  MyGameMain_Render3D_L3()
{
}