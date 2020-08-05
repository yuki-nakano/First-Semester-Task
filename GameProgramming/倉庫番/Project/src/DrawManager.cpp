
#include "DxLib.h"
#include "GameDefinition.h"
#include "DrawManager.h"

/**
���摜�ɂ���
	���ꂼ��̃T�C�Y�� ��:32, �c:32 �ł�
*/


// ================================================================================
// �O���[�o���֐�
// ================================================================================
// �摜�f�[�^�n���h��
int PlayerGraphHandle[DIR_MAX][DIR_IMAGE_MAX];
int GroundGraphHandle;
int BlockGraphHandle;
int CrateGraphHandle[����];		// �N���[�g�̎�ލő吔
int ClearGraphHandle;

// �A�j���[�V�����̃C���f�b�N�X�z��
int ANIME_IDX_ARRAY[PLAYER_ANIME_MAX] = { 0, 1, 0, 2 };


// ================================================================================
// �`�揈�������� (�Q�[���N�����Ɉ�x�����Ăяo��)
// ================================================================================
void DrawInit()
{
	// �摜�n���h����ێ�����ϐ��̏�����
	for( int i = 0; i < DIR_MAX; i++ )
	{
		for( int j = 0; j < DIR_IMAGE_MAX; j++ )
		{
			PlayerGraphHandle[i][j] = -1;
		}
	}
	GroundGraphHandle = -1;
	BlockGraphHandle = -1;
	for( int i = 0; i < ����; i++ )
	{
		CrateGraphHandle[i] = -1;
	}
	ClearGraphHandle = -1;

	// �摜�f�[�^�ǂݍ���
	for( int i = 0; i < DIR_MAX; i++ )
	{
		for( int j = 0; j < DIR_IMAGE_MAX; j++ )
		{
			char str[256];
			sprintf_s( str, sizeof(str), "data/Player/player_%02d.png", (i * DIR_IMAGE_MAX) + j );
			PlayerGraphHandle[i][j] = LoadGraph( str );
		}
	}

	GroundGraphHandle = LoadGraph( "data/Ground/ground.png" );
	BlockGraphHandle = LoadGraph( "data/Ground/block.png" );
	for( int i = 0; i < ����; i++ )
	{
		char str[256];
		sprintf_s( str, sizeof(str), "data/Crate/crate_%02d.png", i );
		CrateGraphHandle[i] = LoadGraph( str );
	}

	ClearGraphHandle = LoadGraph( "data/Clear.png" );
}

// ================================================================================
// ������������������
// true = ����
// false = ���s
// ================================================================================
bool InitSuccessed()
{
	for( int i = 0; i < DIR_MAX; i++ )
	{
		for( int j = 0; j < DIR_IMAGE_MAX; j++ )
		{
			if( PlayerGraphHandle[i][j] == -1 )
			{
				return false;
			}
		}
	}

	if( GroundGraphHandle == -1)
	{
		return false;
	}

	if( BlockGraphHandle == -1)
	{
		return false;
	}

	for( int i = 0; i < ����; i++ )
	{
		if( CrateGraphHandle[i] == -1)
		{
			return false;
		}
	}

	if( ClearGraphHandle == -1 )
	{
		return false;
	}

	return true;
}

// ================================================================================
// �`�揈���I���@ (�Q�[���I�����ADxLib_End�̑O�Ɉ�x�����Ăяo��)
// ================================================================================
void DrawEnd()
{
	for( int i = 0; i < DIR_MAX; i++ )
	{
		for( int j = 0; j < DIR_IMAGE_MAX; j++ )
		{
			DeleteGraph( PlayerGraphHandle[i][j] );
		}
	}
	DeleteGraph( GroundGraphHandle );
	DeleteGraph( BlockGraphHandle );
	for( int i = 0; i < ����; i++ )
	{
		DeleteGraph( CrateGraphHandle[i] );
	}
}

// ================================================================================
// �Q�[���̔z�u����`��@�i�v���C���[�̓A�j���[�V���������邽�ߕʊ֐��j
// x = �}�X��x���W
// y = �}�X��y���W
// type = �z�u���̎��
// ================================================================================
void DrawObject( int x, int y, int type )
{
	�����@�R�����g�ɍ��킹�ĕ`�揈�����R�[�f�B���O
	// �}�X�̍��W���A��ʍ��W�֕ϊ�

	// �n�ʂ̕`��

	// �z�u���̕`��
}

// ================================================================================
// �v���C���[��`��
// x = �}�X��x���W
// y = �}�X��y���W
// dir = �v���C���[�̍��̌���
// animeNo = ���s�p�^�[���ԍ�
// ================================================================================
void DrawPlayer( int x, int y, int dir, int animeNo )
{
	�����@�`�揈�����R�[�f�B���O
	// �܂��͂P�̉摜��\�����邾����ڎw��
	// �ŏI�I�ɁA�����Ă�������̉摜�ŃA�j���[�V�������Ă���΍ō�
}

// ================================================================================
// �Q�[���N���A�̕�����`��
// ================================================================================
void DrawGameClear()
{
	DrawGraph( (WINDOW_W / 2) - 160, (WINDOW_H / 2) - 160, ClearGraphHandle, TRUE );
}
