#pragma once
#pragma warning(disable : 4996)

//-------------------------------------------------------------------------
//�G�t�F�N�g��b�N���X
//-------------------------------------------------------------------------
#include "GameEngine_Ver3_7.h"


class BEffect 
{
	//�ύX�s��------------------------------------------------
public:
	typedef  shared_ptr<BEffect>	SP;
	typedef  weak_ptr<BEffect>		WP;

	//�ύX�\---------------------------------------------------

public:
	//�ϐ�
	//---------------------------------------------------------------------------------------------
	//�G�t�F�N�g�n���h��
	//0�ԁF�L�����N�^����
	//1�ԁF�A�C�e������
	//2�ԁF�A�C�e������
	//3�ԁF�G�l�~�[���n
	//4�ԁF�G�l�~�[�ƏՓ�
	//5�ԁF�ǂƏՓ�
	//6�ԁF�����ې���
	//7�ԁF�����ۏ���
	//8�ԁF�����ۂƏՓ�
	//9�ԁF�L�����N�^���S
	//---------------------------------------------------------------------------------------------
	enum effType
	{
		CLEAR = -1,
		CreateCharactor = 0,
		CreateItem,
		DestroyItem,
		EnemyLanding,
		Hit_to_Enemy,
		Hit_to_Wall,
		CreateTail,
		DestroyTail,
		Hit_to_Tail,
		DestroyCharactor
	};
	effType playing_EffectHandle;
	int effect_Life;
	
	ML::Vec3 pos;//�G�t�F�N�g�Đ��ʒu
	ML::Vec3 angle;//�G�t�F�N�g�Đ��p�x
	ML::Vec3 scale;//�G�t�F�N�g�̑傫��
	ML::Vec3 moveVec;//�G�t�F�N�g�̈ړ����x
	float alpha;//�����x

	string meshName;//���b�V���̖��O
	string filePath;//���b�V���̃p�X

	//���\�b�h
	//�������Ń��b�V����ǂݍ��ފ֐�
	void LoadEffect(effType handle);	
	//�������֐�
	void Eff_Initialize(ML::Vec3 pos, ML::Vec3 angle, effType handle);

	//��������
	BEffect() :
		pos(0, 0, 0),
		angle(0, 0, 0),
		scale(0,0,0),
		moveVec(0,0,0),
		playing_EffectHandle(CLEAR),
		effect_Life(0),
		alpha(1)
	{
		
	}

	virtual ~BEffect(){}
};