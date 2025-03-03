#include "get_next_line.h"

char    *get_line(char *left_str)
{
        size_t  line_len;
        char    *line;
	char	*new_position;

        new_position = ft_strchr(left_str, '\n');
        if (new_position != NULL)
        {
                line_len = new_position - left_str + 1;
                line = ft_substr(left_str, 0, line_len);
        }
        else
        {
                line = ft_strdup(left_str);
                if (*line == '\0')
                {
                        free(line);
                        return (NULL);
                }
        }
        return (line);
}

char    *set_new_position(char *left_str)
{
        char    *new_position;
        char    *tmp;

        new_position = ft_strchr(left_str, '\n');
        if (new_position != NULL)
        {
                tmp = ft_strdup(new_position + 1);
                free(left_str);
                new_position = tmp;
        }
        else
        {
                free(left_str);
                left_str = NULL;
                return (NULL);
        }
        return (new_position);
}

char    *fill_left_str(int fd, char *left_str, char *buff)
{
        int             bytesread;
        char    *tmp;

        while (1)
        {
                bytesread = read(fd, buff, BUFFER_SIZE);
                if (bytesread <= 0)
                        break ;
                buff[bytesread] = '\0';
                if (left_str == NULL)
                        left_str = ft_strdup(buff);
                else
                {
                        tmp = ft_strjoin(left_str, buff);
                        free(left_str);
                        left_str = tmp;
                }
                if (ft_strchr(buff, '\n') != NULL)
                        break ;
        }
        free(buff);
        return (left_str);
}

char    *get_next_line(int fd)
{
        static char     *left_str;
        char            *line;
        char            *buff;

        if (fd < 0 || BUFFER_SIZE <= 0)
                return (NULL);
        buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (buff == NULL)
                return (NULL);
        left_str = fill_left_str(fd, left_str, buff);
        if (left_str == NULL || *left_str == '\0')
        {
                free(left_str);
                return (NULL);
        }
	line = get_line(left_str);
	left_str = set_new_position(left_str);
	return (line);
}
