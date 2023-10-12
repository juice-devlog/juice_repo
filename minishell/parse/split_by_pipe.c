char	**split_by_pipe(char *line)
{
	char	**result;
	int		process_cnt;
	int		in_quote;

	while (*line)
	{
		if (*line == '\'' || *line == '"')
		{
			if (in_quote == 0)
			{
				in_quote = *line;
				start = line + 1;
			}
			else if (in_quote == *line)
				in_quote = 0;
		}
		else if (*line == '|')
		{
			if (in_quote == 0)
				
		}
	}
}