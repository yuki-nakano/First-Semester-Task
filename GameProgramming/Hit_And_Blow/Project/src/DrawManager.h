#pragma once

// ================================================================================
// �`�揈���֐��Q
// ================================================================================
void DrawInit();	// �`�揈�������� (�Q�[���N�����Ɉ�x�����Ăяo��)
void DrawEnd();		// �`�揈���I���@ (�Q�[���I�����ADxLib_End�̑O�Ɉ�x�����Ăяo��)

void DrawInformation();									// ��񕶏͂�`��
void DrawGameClear();									// �Q�[���N���A�̕�����`��
void DrawHint( int hit, int blow, int count );			// Hit, Blow, ���͉񐔂�`��
void DrawNum( int* array, int digit );					// ���͐�����`��
void DrawCursor( int cursor, bool isValid, int digit );	// �J�[�\����`��
