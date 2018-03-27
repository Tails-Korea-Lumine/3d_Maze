//-------------------------------------------------------------------
//�ǔ��J�����}��
//-------------------------------------------------------------------
#include  "MyPG.h"
#include "Task_CameraMan.h"
#include "Task_Player.h"

namespace  CameraMan
{
	Resource::WP  Resource::instance;
	//-------------------------------------------------------------------
	//���\�[�X�̏�����
	bool  Resource::Initialize()
	{		
		return true;
	}
	//-------------------------------------------------------------------
	//���\�[�X�̉��
	bool  Resource::Finalize()
	{
		return true;
	}
	//-------------------------------------------------------------------
	//�u�������v�^�X�N�������ɂP�񂾂��s������
	bool  Object::Initialize()
	{
		//�X�[�p�[�N���X������
		__super::Initialize(defGroupName, defName, true);
		//���\�[�X�N���X����or���\�[�X���L
		this->res = Resource::Create();

		//���f�[�^������
		this->dist = ML::Vec3(-600, +300, 0);
		//�J�����̐ݒ�
		ge->camera[0] = MyPG::Camera::Create(
			ML::Vec3(600,300,600),				//	�^�[�Q�b�g�ʒu
			ML::Vec3(0,400,600),			//	�J�����ʒu
			ML::Vec3(0.0f, 1.0f, 0.0f),					//	�J�����̏�����x�N�g��
			ML::ToRadian(35), 10.0f, 4000.0f,	//	����p�E���싗��
			(float)ge->screenWidth / (float)ge->screenHeight);		//	��ʔ䗦		
		DG::EffectState().param.bgColor = ML::Color(1, 0, 0, 0);
		//���^�X�N�̐���

		return  true;
	}
	//-------------------------------------------------------------------
	//�u�I���v�^�X�N���Ŏ��ɂP�񂾂��s������
	bool  Object::Finalize()
	{
		//���f�[�^���^�X�N���


		if (!ge->QuitFlag() && this->nextTaskCreate)
		{
			//�������p���^�X�N�̐���
			//auto nextTask = Game::Object::Create(true);
		}

		return  true;
	}
	//-------------------------------------------------------------------
	//�u�X�V�v�P�t���[�����ɍs������
	void  Object::UpDate()
	{
		auto in1 = DI::GPad_GetState("P1");
		auto p = ge->GetTask_One_G<Player::Object>("�v���C��");

		if (p == nullptr || ge->gameoverFlag) { return; }

		this->angle.y = in1.LStick.axis.x * ML::ToRadian(4);
		if (in1.HL.on)
		{
			this->angle.y -= ML::ToRadian(4);			
		}
		if (in1.HR.on)
		{
			this->angle.y += ML::ToRadian(4);			
		}

		ML::Mat4x4 matR;
		matR.RotationY(this->angle.y);
		this->dist = matR.TransformCoord(this->dist);

		ge->camera[0]->target = p->pos + ML::Vec3(0, 200, 0);;
		ge->camera[0]->pos = p->pos + this->dist;

	}
	//-------------------------------------------------------------------
	//�u�Q�c�`��v�P�t���[�����ɍs������
	void  Object::Render2D_AF()
	{
	}

	void  Object::Render3D_L0()
	{

	}
	//������������������������������������������������������������������������������������
	//�ȉ��͊�{�I�ɕύX�s�v�ȃ��\�b�h
	//������������������������������������������������������������������������������������
	//-------------------------------------------------------------------
	//�^�X�N��������
	Object::SP  Object::Create(bool  flagGameEnginePushBack_)
	{
		Object::SP  ob = Object::SP(new  Object());
		if (ob) {
			ob->me = ob;
			if (flagGameEnginePushBack_) {
				ge->PushBack(ob);//�Q�[���G���W���ɓo�^
			}
			if (!ob->B_Initialize()) {
				ob->Kill();//�C�j�V�����C�Y�Ɏ��s������Kill
			}
			return  ob;
		}
		return nullptr;
	}
	//-------------------------------------------------------------------
	bool  Object::B_Initialize()
	{
		return  this->Initialize();
	}
	//-------------------------------------------------------------------
	Object::~Object() { this->B_Finalize(); }
	bool  Object::B_Finalize()
	{
		auto  rtv = this->Finalize();
		return  rtv;
	}
	//-------------------------------------------------------------------
	Object::Object() {	}
	//-------------------------------------------------------------------
	//���\�[�X�N���X�̐���
	Resource::SP  Resource::Create()
	{
		if (auto sp = instance.lock()) {
			return sp;
		}
		else {
			sp = Resource::SP(new  Resource());
			if (sp) {
				sp->Initialize();
				instance = sp;
			}
			return sp;
		}
	}
	//-------------------------------------------------------------------
	Resource::Resource() {}
	//-------------------------------------------------------------------
	Resource::~Resource() { this->Finalize(); }
}