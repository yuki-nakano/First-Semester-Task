#pragma once

// ================================================================================
// �`�揈���֐��Q
// ================================================================================
void DrawInit();	// �`�揈�������� (�Q�[���N�����Ɉ�x�����Ăяo��)
void DrawEnd();		// �`�揈���I���@ (�Q�[���I�����ADxLib_End�̑O�Ɉ�x�����Ăяo��)

void DrawInformation( int turn );			// ��񕶏͂�`��
void DrawGameClear( int winner );			// �Q�[���N���A�̕�����`��
void DrawBgLine();							// �g����`��
void DrawStone( int x, int y, int stone );	// �Ֆʂ̃}�X(x, y)�ɐ΂�`��
void DrawCursor( int x, int y );			// �J�[�\����`��
 