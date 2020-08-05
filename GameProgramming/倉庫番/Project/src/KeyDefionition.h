#pragma once

#include "DxLib.h"

// ================================================================================
// �L�[��`
// ================================================================================

// �L�[���
#define MY_INPUT_UP		0	// ��L�[
#define MY_INPUT_DOWN	1	// ���L�[
#define MY_INPUT_LEFT	2	// ���L�[
#define MY_INPUT_RIGHT	3	// �E�L�[
#define MY_INPUT_RESET	4	// ���Z�b�g�{�^��
#define MY_INPUT_MAX	5	// ���̓L�[�̍ő吔

#define MY_INPUT_START	MY_INPUT_UP
#define MY_INPUT_END	MY_INPUT_MAX

// �L�[�A�T�C��
const int KEY_ASSIGN[MY_INPUT_MAX]
{
	KEY_INPUT_UP,		// MY_INPUT_UP
	KEY_INPUT_DOWN,		// MY_INPUT_DOWN
	KEY_INPUT_LEFT,		// MY_INPUT_LEFT
	KEY_INPUT_RIGHT,	// MY_INPUT_RIGHT
	KEY_INPUT_R,		// MY_INPUT_RESET
};
