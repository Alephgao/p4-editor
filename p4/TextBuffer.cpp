
#include <stdio.h>
#include <iostream>
#include <string>
#include "TextBuffer.hpp"

using namespace std;

#include "TextBuffer.hpp"

// Constructor
TextBuffer::TextBuffer() {
    cursor = data.end();
    row = 1;
    column = 0;
    index = 0;
}

// Moves the cursor one position forward
bool TextBuffer::forward() {
    if (cursor == data.end()) {
        return false;
    }
    if (data_at_cursor() == '\n') {
        row++;
        column = 0;
    } else {
        column++;
    }
    index++;
    cursor++;
    return true;
}

// Moves the cursor one position backward
bool TextBuffer::backward() {
    if (cursor == data.begin()) {
        return false;
    }
    cursor--;
    index--;
    if (data_at_cursor() == '\n') {
        row--;
        column = compute_column();
    } else {
        column--;
    }
    return true;
}

// Inserts a character at the cursor
void TextBuffer::insert(char c) {
    data.insert(cursor, c);
    if (c == '\n') {
        row++;
        column = 0;
    } else {
        column++;
    }
    index++;
}


// Removes the character at the cursor
bool TextBuffer::remove() {
    if (is_at_end()) {
        return false;
    }
    char c = data_at_cursor();

    cursor = data.erase(cursor);

    if (data.empty()) { 
        row = 1;
        column = 0;
        index = 0;
        return true;
    }

    if (c == '\n') {
            column = compute_column();
    }

    return true;
}





// Moves the cursor to the start of the current row
void TextBuffer::move_to_row_start() {
    while (column != 0){
      cursor--;
      column--;
      index--;
    }
}

// Moves the cursor to the end of the current row
void TextBuffer::move_to_row_end() {
    while (cursor != data.end() && data_at_cursor()!='\n'){
      ++cursor;
      ++column;
      ++index;
    }
}

/*
// Moves the cursor to the specified column in the current row
void TextBuffer::move_to_column(int new_column) {
    move_to_row_start();
    while (column<=new_column && cursor != data.end() && data_at_cursor() != '\n'){
      forward();
    }
}
*/

void TextBuffer::move_to_column(int new_column) {
    move_to_row_start(); 
    int current_col = 0;

    while (current_col < new_column && cursor != data.end() && data_at_cursor() != '\n') {
        forward();
        current_col++;
    }
}

// Moves the cursor up to the previous row
bool TextBuffer::up() {


   if (row == 1) {  
        return false;
    }

    int goalCol = column;
    move_to_row_start();  
    backward();          
    move_to_row_start();  

    for (int col = 0; col < goalCol && cursor != data.end() 
         && data_at_cursor() != '\n'; col++) {
        forward();
    }

    return true;
}

// Moves the cursor down to the next row
bool TextBuffer::down() {
    if (is_at_end()) {
        return false;
    }
    int goalCol = column;
    move_to_row_end();  
    if (cursor == data.end()) {
        return false;  
    }
    
    forward();  
    column = 0; 
    for (int col = 0; col < goalCol && cursor != data.end() 
         && data_at_cursor() != '\n'; col++) {
        forward();
    }

    return true;
}

// Checks if the cursor is at the end of the text
bool TextBuffer::is_at_end() const {
    return cursor == data.end();
}

// Returns the character at the cursor
char TextBuffer::data_at_cursor() const {
    if (cursor != data.end()) {
        return *cursor;
    }
    return '\0';  
}

// Returns the current row
int TextBuffer::get_row() const {
    return row;
}

// Returns the current column
int TextBuffer::get_column() const {
    return column;
}

// Returns the index of the current cursor position
int TextBuffer::get_index() const {
    return index;
}

// Returns the size of the text buffer
int TextBuffer::size() const {
    return static_cast<int>(data.size());
}

// Returns the contents of the text buffer as a string
std::string TextBuffer::stringify() const {
    return std::string(data.begin(), data.end());
}

// Computes the column of the cursor within the current row
int TextBuffer::compute_column() const {
    int column = 0;
    Iterator it = cursor;  
    while (it != data.begin() && *(--it) != '\n') {
        ++column;
    }
    return column;
}
