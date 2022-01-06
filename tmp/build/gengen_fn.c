#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef int Fd;
enum {
	fd_read_e = 0,
	fd_write_e = 1,
};

static void fileCopy(FILE* a_dest, FILE* a_src) {
	for (char c = fgetc(a_src); c != EOF; ) {
		fputc(c, a_dest);
		c = fgetc(a_src);
	}
	fflush(a_dest);
}

static void filePrint(FILE* a_file) {
	fileCopy(stdout, a_file);
	fputs("End File Print.\n", stderr);
}

FILE* fnNames(FILE* a_lines) {
	Fd pipe_in[2], pipe_out[2];

	// fileCopy(stderr, a_lines);
	
	int pipe_in_res = pipe(pipe_in);
	if (pipe_in_res != 0) { perror("pipe_in"); exit(EXIT_FAILURE); }
	int pipe_out_res = pipe(pipe_out);
	if (pipe_out_res != 0) { perror("pipe_out"); exit(EXIT_FAILURE); }
	const pid_t child_pid = fork();

	if (child_pid == -1) { // Error Fork
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0) { // Child code
		fputs("Starting child\n", stderr);
		dup2(pipe_in[fd_read_e], STDIN_FILENO);
		dup2(pipe_out[fd_write_e], STDOUT_FILENO);
		close(pipe_in[fd_write_e]);
		//close(pipe_out[fd_read_e]);
		//close(pipe_in[fd_read_e]);
		//close(pipe_out[fd_write_e]);
		// fputs("Done duplicating fd\n", stderr);

		// fileCopy(stderr, stdin);

		// const char* prog = "cat";
		// execlp(prog, prog, NULL);

		// const char* prog = "echo";
		// execlp(prog, prog, "hello", "world", NULL);

		/*
		const char* prog = "cat";
		execlp(
			prog,
			prog,
			NULL);
		*/		
		const char* prog = "grep";
		execlp(
			prog,
			prog,
			"-oP",
			"(?<=\\()[a-zA-Z0-9 *_]+[ |*](?=[a-zA-Z0-9_]+)",
			NULL);
		
	}

	// Parent code
	fputs("Starting parent\n", stderr);
	// close(pipe_in[fd_read_e]);
	// close(pipe_out[fd_write_e]);
	
	FILE* data_in = fdopen(pipe_in[fd_write_e], "w");
	if (data_in == NULL) { perror("data_in"); exit(EXIT_FAILURE); }
	fileCopy(data_in, a_lines);
	FILE* data_out = fdopen(pipe_out[fd_read_e], "r");
	if (data_in == NULL) { perror("data_out"); exit(EXIT_FAILURE); }
	
	// const char* txt = "\nA\n";
	// write(pipe_in[fd_write_e], txt, strlen(txt));
	close(pipe_in[fd_write_e]);
	// close(pipe_out[fd_read_e]);
	// close(pipe_in[fd_read_e]);
	close(pipe_out[fd_write_e]);
		
	waitpid(child_pid, NULL, 0);
	return data_out;		
}

// exec a shell program (similar to execvp)
// with stdin set to a_input_file and stdout set to a_output_file
// a_input_file must be readable. a_output_file must be writeable
// RETURNS: The pid of the child, in case you want to wait for it.
// CALLER: is responsible for closing input & output files.
pid_t execWithFiles(
	FILE* a_output_file,
	FILE* a_input_file,
	const char* a_file,
	char* const argv[],
) {
	// TODO(ailijic): copy the stuff from the above function

}

int main() {
	fputs("Starting...\n", stderr);
	FILE* lines = fopen("lines.txt", "r");
	fputs("Opened lines.txt\n", stderr);
	if (lines == NULL) { perror("lines"); exit(EXIT_FAILURE); }

	FILE* fn_names = fnNames(lines);
	filePrint(fn_names);

	fclose(fn_names);
}