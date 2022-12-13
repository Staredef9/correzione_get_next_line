#include "get_next_line.h"

char *line_read_and_save(char *memorized_lines, int fd)
{	
	char	*temporary_buffer;
	int	counter;
	
	temporary_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	counter = 1;
	while (!ft_strchr(memorized_lines, '\n') && counter > 0)
	{
		counter = read(fd, temporary_buffer, BUFFER_SIZE);
		temporary_buffer[counter] = '\0';
		memorized_lines = ft_strjoin(memorized_lines, temporary_buffer);
	}
	if (counter == -1)
	{
		free (temporary_buffer);
		temporary_buffer = NULL;
		return (NULL);
	}
	free(temporary_buffer);
	temporary_buffer = NULL;
	return (memorized_lines);
}//memory leak qua sicuro.....
//da freeare in altra funzione. Lo si puo' fare perche' e' statica. 

char	*line_move_to_return(char *memorized_lines)
{
	int	counter;
	char	*to_return;

	counter = 0;
	if (!memorized_lines[counter])
		return (NULL);
	while (memorized_lines[counter] != '\n')
		counter ++;
	counter += 2;
	to_return = malloc(sizeof(char) * counter);
	ft_strlcpy(to_return, memorized_lines, counter);
	return (to_return);
	//d trovare la lunghezza fino a \n di memorized_lines
	//copiare in to_return e aggiungere il \n in fondo 
	//restituire il tutto nel main a line to return
	//questa verra' liberata nel main vero. 
}

char	*lines_forward_and_free(char *memorized_lines)
{
	int	counter;
	int	second_counter;
	char	*next_line;
	
	counter = 0;
	second_counter = 0;
	while ( memorized_lines[counter] != '\n')
		counter ++;
	counter += 1;
	next_line = malloc(sizeof(char) * (ft_strlen(memorized_lines) - counter + 1));
	if (!next_line)
		return (NULL);
	while (memorized_lines[counter] != '\0')
	{
		next_line[second_counter] = memorized_lines[counter];
		second_counter ++;
		counter ++;
	}
	next_line[second_counter] = '\0';
	free(memorized_lines);
	memorized_lines = NULL;
	return (next_line);
}

char *get_next_line(int fd)
{
    static char *memorized_lines;
    char *line_to_return;

    if (fd < 0 || BUFFER_SIZE <= 0)
	    return (0);
	memorized_lines = line_read_and_save(memorized_lines, fd);
	line_to_return = line_move_to_return(memorized_lines);
	memorized_lines = lines_forward_and_free(memorized_lines);
	return (line_to_return);
}
