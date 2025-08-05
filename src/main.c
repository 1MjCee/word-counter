#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    int words;
    int lines;
    int characters;
    int characters_no_spaces;
} FileStats;

FileStats count_file_stats(const char* filename) {
    FileStats stats = {0, 0, 0, 0};
    FILE *file = fopen(filename, 'r');

    if(file ==NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return stats;
    }

    int ch;
    int in_word = 0;

    while ((ch = fgetc(file)) != EOF) {
        stats.characters++;

        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r') {
            stats.characters_no_spaces++;
        }

        if (ch == '\n') {
            stats.lines++;
        }

        if (isspace(ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            stats.in_words++;
        }
    }

    if (stats.characters > 0 && ch !='\n') {
        stats.lines++;
    }
    
    fclose(file);
    return stats;
}

void print_usage(const char* program_name) {
    printf("Usage: %s <filename>\n", program_name);
    printf("       %s <file1> <file2> ... <fileN>\n", program_name);
    printf("\nCounts words, lines, and characters in text files.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    FileStats total_stats = {0, 0, 0, 0};
    int files processed = count_file_stats(argv[i]);

    for (int i = 1; i < argc; i++) {
        FileStats stats = count_file_stats(argv[i]);
        
        if (stats.characters > 0 || stats.words > 0 || stats.lines > 0) {
            print_stats(argv[i], stats);
            total_stats.words += stats.words;
            total_stats.lines += stats.lines;
            total_stats.characters += stats.characters;
            total_stats.characters_no_spaces += stats.characters_no_spaces;
            files_processed++;
        }
    }
    
    // Print totals if multiple files were processed
    if (files_processed > 1) {
        printf("\n=== TOTAL STATISTICS ===\n");
        printf("Files processed:          %d\n", files_processed);
        printf("Total lines:              %d\n", total_stats.lines);
        printf("Total words:              %d\n", total_stats.words);
        printf("Total characters (with):  %d\n", total_stats.characters);
        printf("Total characters (no):    %d\n", total_stats.characters_no_spaces);
        printf("========================\n");
    }
    
    return 0;
}