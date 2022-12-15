#pragma once
#ifndef __GAME_H__
#define __GAME_H__

void menu();
void credit();

void baseball_setup_solo();
void baseball_check_solo(int* player);
void baseball_result_solo();
void baseball_start_solo();

void baseball_check_duo_same(int firset_turn, int* p1, int* p2);
void baseball_result_duo_same(int turn);
void baseball_start_duo_same();

void baseball_start_duo_diff();
void baseball_check_duo_diff(int firset_turn, int* p1, int* p2);
void baseball_setup_duo();

void baseball_solo_time_attack();
int timer();
void _round(int player);

void baseball_start_duo_round_mode();

int first_scond();

void baseball_start_com();
void baseball_check_com(int* com);

#endif // !__GAME_H__
