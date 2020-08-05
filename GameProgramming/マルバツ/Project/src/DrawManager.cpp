
#include "DxLib.h"
#include "WinMain.h"
#include "DrawManager.h"


#define CELLSIZE			100		// �P�}�X�̃T�C�Y
#define CURSORSIZE			96		// �J�[�\���̃T�C�Y
#define CIRCLE_R			48		// �v���C���[�~�̔��a

#define DRAW_OFFSET_X		10		// �`��I�t�Z�b�g�w
#define DRAW_OFFSET_Y		60		// �`��I�t�Z�b�g�x

#define GAME_AREA_WIDTH		(STAGE_WIDTH * CELLSIZE)	// �Q�[���G���A��
#define GAME_AREA_HEIGHT	(STAGE_HEIGHT * CELLSIZE)	// �Q�[���G���A����


// ================================================================================
// �`�揈�������� (�Q�[���N�����Ɉ�x�����Ăяo��)
// ================================================================================
void DrawInit()
{
}

// ================================================================================
// �`�揈���I���@ (�Q�[���I�����ADxLib_End�̑O�Ɉ�x�����Ăяo��)
// ================================================================================
void DrawEnd()
{
}

// ================================================================================
// ��񕶏͂�`��
// truen = ���݂̎��
// ================================================================================
void DrawInformation( int turn )
{
	DrawString( 10, 10, "�c�A���A�΂߂ɐ΂𑵂��悤�I", GetColor(0,0,0) );

	DrawString( 10, 380, "������@", GetColor(80,80,80) );
	DrawString( 10, 400, "���������@�F�J�[�\���ړ�", GetColor(80,80,80) );
	DrawString( 10, 420, "�d�m�s�d�q�F�΂�u��", GetColor(80,80,80) );
}

// ================================================================================
// �Q�[���N���A�̕�����`��
// ================================================================================
void DrawGameClear( int winner )
{
	int left   = DRAW_OFFSET_X + 400;
	int top    = DRAW_OFFSET_Y;
	int center_x = left + int(CELLSIZE * 0.5);
	int center_y = top + 20 + int(CELLSIZE * 0.5);

	switch( winner )
	{
	case WINNER_WHITE:
		DrawString(left + 20, top, "Winner", GetColor(0,255,0) );
		DrawCircle(center_x, center_y, CIRCLE_R, GetColor(0xFF, 0xFF, 0xFF), TRUE);
		break;

	case WINNER_BLACK:
		DrawString(left + 20, top, "Winner", GetColor(0,0,0) );
		DrawCircle(center_x, center_y, CIRCLE_R, GetColor(0x00, 0x00, 0x00), TRUE);
		break;

	case WINNER_DRAW:
		DrawString( left, top, "���������I", GetColor(80,80,80) );
		break;
	}
}

// ================================================================================
// �g����`��
// ================================================================================
void DrawBgLine()
{
	const int left   = DRAW_OFFSET_X-1;
	const int top    = DRAW_OFFSET_Y-1;
	const int right  = left + GAME_AREA_WIDTH  + 1;
	const int bottom = top  + GAME_AREA_HEIGHT + 1;

	// �O�g
	DrawLine( left,  top,    right, top,    GetColor( 0xFF, 0xFF, 0xFF) );
	DrawLine( right, top,    right, bottom, GetColor( 0xFF, 0xFF, 0xFF) );
	DrawLine( right, bottom, left,  bottom, GetColor( 0xFF, 0xFF, 0xFF) );
	DrawLine( left,  bottom, left,  top,    GetColor( 0xFF, 0xFF, 0xFF) );

	// ���g
	DrawLine(left + ((GAME_AREA_WIDTH / 3) * 1), top, left + ((GAME_AREA_WIDTH / 3) * 1), bottom, GetColor(0xFF, 0xFF, 0xFF));
	DrawLine(left + ((GAME_AREA_WIDTH / 3) * 2), top, left + ((GAME_AREA_WIDTH / 3) * 2), bottom, GetColor(0xFF, 0xFF, 0xFF));
	DrawLine(left, top + ((GAME_AREA_HEIGHT / 3) * 1), right, top + ((GAME_AREA_HEIGHT / 3) * 1), GetColor(0xFF, 0xFF, 0xFF));
	DrawLine(left, top + ((GAME_AREA_HEIGHT / 3) * 2), right, top + ((GAME_AREA_HEIGHT / 3) * 2), GetColor(0xFF, 0xFF, 0xFF));
}

// ================================================================================
// �Ֆʂ̃}�X(x, y)�ɐ΂�`��
// x = �}�X�� x���W
// y = �}�X�� y���W
// stone = �z�u����΂̒l
// ================================================================================
void DrawStone( int x, int y, int stone )
{
	const int center_x = DRAW_OFFSET_X + (x * CELLSIZE) + int(CELLSIZE * 0.5);
	const int center_y = DRAW_OFFSET_Y + (y * CELLSIZE) + int(CELLSIZE * 0.5);
	switch( stone )
	{
	case STONE_WHITE:
		DrawCircle(center_x, center_y, CIRCLE_R, GetColor(0xFF, 0xFF, 0xFF), TRUE);
		break;

	case STONE_BLACK:
		DrawCircle(center_x, center_y, CIRCLE_R, GetColor(0x00, 0x00, 0x00), TRUE);
		break;
	}
}

// ================================================================================
// �J�[�\����`��
// x = �}�X�� x���W
// y = �}�X�� y���W
// ================================================================================
void DrawCursor( int x, int y )
{
	const int left		= DRAW_OFFSET_X + (x * CELLSIZE) + int((CELLSIZE - CURSORSIZE)*0.5);
	const int top		= DRAW_OFFSET_Y + (y * CELLSIZE) + int((CELLSIZE - CURSORSIZE)*0.5);
	DrawBox( left, top, left+ CURSORSIZE, top+ CURSORSIZE, GetColor( 0xFF, 0x00, 0x00), FALSE );
}
