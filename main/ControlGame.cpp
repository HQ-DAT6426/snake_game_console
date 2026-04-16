#include <iostream>
#include <windows.h>
#include "Map.h"
#include "Snake.h"
#include "Food.h"
#include "ControlGame.h"
#include <conio.h>
#include <vector>
#include <deque>
#include <exception>

ControlGame::ControlGame(): m(),f(m.getH(),m.getW()),s(m.getH(),m.getW()){
    isGameover = false;
}
ControlGame::ControlGame(int h,int w): m(h,w),f(h,w),s(h,w){
    isGameover = false;
}
void ControlGame::handleInput(){
    if(_kbhit()){
        char ch = _getch();
        s.setDirection(ch);
    }
}
bool ControlGame::SameFoodBody(){
    return s.isBody(f.getPosFood());
}
void ControlGame::update(){

    if(hitWall(s.getHeadPoint())){
        isGameover = true;
        return;
    }
    else if(f.isFood(s.getHeadPoint())){
        s.moveDir(true);
        f.createFood(m.getW(), m.getH());
        while(SameFoodBody()) f.createFood(m.getW(), m.getH());
    }else s.moveDir(false);
}

bool ControlGame::hitWall(Point head){
    if(s.isBody(head)) return true;
    if(m.isWall(head)) return true;
    return false;
}
void ControlGame::gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void ControlGame::draw() {
    //system("cls");
    gotoXY(0,0);

    int width = m.getW();
    int height = m.getH();

    // 1. CHUẨN BỊ BẢN NHÁP (Mảng 2 chiều)
    // Tạo một mảng ký tự và lấp đầy bằng không khí (khoảng trắng)
    std::vector<std::vector<char>> buffer(height, std::vector<char>(width, ' '));

    // 2. VẼ TƯỜNG LÊN NHÁP (Lấy từ Map)
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            if(m.isWall(Point(x, y))) {
                buffer[y][x] = '#';
            }
        }
    }

    // 3. VẼ MỒI LÊN NHÁP
    Point food = f.getPosFood();
    buffer[food.getY()][food.getX()] = 'X';

    // 4. VẼ RẮN LÊN NHÁP (Chỉ cần lặp đúng 1 vòng theo chiều dài rắn!)
    std::deque<Point> b = s.getBody();
    for (int i = 0; i < b.size(); i++) {
        int sx = b[i].getX();
        int sy = b[i].getY();

        if (i == b.size() - 1) {
            buffer[sy][sx] = 'O'; // Đầu rắn
        } else {
            buffer[sy][sx] = 'o'; // Thân rắn
        }
    }

    // 5. IN TOÀN BỘ BẢN NHÁP RA MÀN HÌNH (Chỉ in, không cần if/else tính toán gì nữa)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << buffer[y][x];
        }
        std::cout << "\n";
    }

    // Hiển thị điểm số
    if (isGameover) {
        std::cout << "\n=== GAME OVER! ===\n";
        std::cout << "Diem cua ban: " << b.size() - 3 << "\n";
    }
}
void ControlGame::startGame(){
    while (isGameover == false) {
        draw();
        handleInput();
        update();

        Sleep(100);
    }
    draw();
}


