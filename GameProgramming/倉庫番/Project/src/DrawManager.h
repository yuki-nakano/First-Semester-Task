#pragma once

// ================================================================================
// �`�揈���֐��Q
// ================================================================================
void DrawInit();		// �`�揈�������� (�Q�[���N�����Ɉ�x�����Ăяo��)
bool InitSuccessed();	// ������������������
void DrawEnd();			// �`�揈���I���@ (�Q�[���I�����ADxLib_End�̑O�Ɉ�x�����Ăяo��)

void DrawObject( int x, int y, int type );				// �Q�[���̔z�u����`��
void DrawPlayer( int x, int y, int dir, int animeNo );	// �v���C���[��`��
void DrawGameClear();									// �Q�[���N���A�̕�����`��
