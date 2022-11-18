#include <stdio.h>

const int rows = 7;
const int columns = 5;
const int panel_count = 10;

typedef enum { false, true } bool;

int *display[panel_count] = {};

int letter_a[rows * columns] = {
    0, 0, 1, 0, 0,
    0, 1, 0, 1, 0,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
};

int letter_b[rows * columns] = {
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 0, 0,
};

void set_serial(bool on) {
    if (on) {
        printf(".");
    } else {
        printf(" ");
    }
}

void write_data() {
    printf("\n");
}

void switch_row(int row) {
    // todo, switch power to this row
};

void print_row(int *ascii_char, int row) {
    int start = row * columns - columns;
    int end = row * columns;

    for (int i = start; i < end; i++) {
        set_serial(ascii_char[i] == 1);
    }
}

void print_char(int *ascii_char) {
    for (int i = 1; i < rows+1; i++) {
        print_row(ascii_char, i);
        write_data();
    }
};

void print_buffer() {
    for (int row = 1; row < rows+1; row++) {    
        for (int i = 0; i < panel_count; i++) {
            if (!display[i]) {
                continue;
            }
            int *current_char = display[i];

            print_row(current_char, row);
        }

        write_data();
        switch_row(row);
    }
}

int main(int argc, char **argv) {
    printf("test\n");


    display[0] = letter_b;
    display[1] = letter_a;
    display[2] = letter_b;
    display[3] = letter_a;
    display[4] = letter_b;
    display[5] = letter_a;

    print_buffer();

    // print_char(display[0]);
    // print_char(letter_b);

    return 0;
}
