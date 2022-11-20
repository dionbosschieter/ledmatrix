#include <stdio.h>
#include <string.h>

const int rows = 7;
const int columns = 5;
const int panel_count = 10;

typedef enum { false, true } bool;

int *display[panel_count] = {};

int space[rows * columns] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};

int char_dot[rows * columns] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 1, 0, 0,
};

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

int letter_c[rows * columns] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};

int letter_d[rows * columns] = {
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 0,
};

int letter_e[rows * columns] = {
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 1,
};

int letter_f[rows * columns] = {
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
};

int letter_g[rows * columns] = {
    0, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 1, 1,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 1,
};

int letter_h[rows * columns] = {
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
};

int letter_i[rows * columns] = {
    0, 1, 1, 1, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 1, 1, 1, 0,
};

int letter_j[rows * columns] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};

int letter_k[rows * columns] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};

int letter_l[rows * columns] = {
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 1,
};

int letter_m[rows * columns] = {
    1, 0, 0, 0, 1,
    1, 1, 0, 1, 1,
    1, 0, 1, 0, 1,
    1, 0, 1, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
};

int letter_n[rows * columns] = {
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 1, 0, 0, 1,
    1, 0, 1, 0, 1,
    1, 0, 0, 1, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
};

int letter_o[rows * columns] = {
    0, 1, 1, 1, 0,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 0,
};

int letter_p[rows * columns] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};

int letter_q[rows * columns] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};

int letter_r[rows * columns] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};

int letter_s[rows * columns] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};

int letter_t[rows * columns] = {
    1, 1, 1, 1, 1,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
};

int letter_u[rows * columns] = {
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 0,
};

int letter_v[rows * columns] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};

int letter_w[rows * columns] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};

int letter_x[rows * columns] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};

int letter_y[rows * columns] = {
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    0, 1, 1, 1, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
};

int letter_z[rows * columns] = {
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 1, 0,
    0, 0, 1, 0, 0,
    0, 1, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 1,
};

void set_serial(bool on) {
    if (on) {
        printf("#");
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
            print_row(space, row);
        }

        write_data();
        switch_row(row);
    }
}

void clear_display() {
    for (int i = 0; i < panel_count; i++) {
        display[i] = space;
    }
}

int *get_display_char_from_char(char character) {
    switch (character) {
        case 'a':
            return letter_a;
        case 'b':
            return letter_b;
        case 'c':
            return letter_c;
        case 'd':
            return letter_d;
        case 'e':
            return letter_e;
        case 'f':
            return letter_f;
        case 'g':
            return letter_g;
        case 'h':
            return letter_h;
        case 'i':
            return letter_i;
        case 'j':
            return letter_j;
        case 'k':
            return letter_k;
        case 'l':
            return letter_l;
        case 'm':
            return letter_m;
        case 'n':
            return letter_n;
        case 'o':
            return letter_o;
        case 'p':
            return letter_p;
        case 'q':
            return letter_q;
        case 'r':
            return letter_r;
        case 's':
            return letter_s;
        case 't':
            return letter_t;
        case 'u':
            return letter_u;
        case 'v':
            return letter_v;
        case 'w':
            return letter_w;
        case 'x':
            return letter_x;
        case 'y':
            return letter_y;
        case 'z':
            return letter_z;
        case '.':
            return char_dot;
        default:
            return space;
    }
}

void write_message_to_display(char *message) {
    if (strlen(message) > panel_count) {
        return;
    }

    for (int i = 0; i < strlen(message); i++) {
        display[i] = get_display_char_from_char(message[i]);
    }
}

int main(int argc, char **argv) {
    printf("test\n");

    char *message = "team.blue";
    write_message_to_display(message);

    print_buffer();

    clear_display();

    return 0;
}
