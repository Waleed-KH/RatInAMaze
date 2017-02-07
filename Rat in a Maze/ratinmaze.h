class ratInMaze
{
private:
	wchar_t maze[10][10];
	int rat[2];
	stack<int> history[2];
	void move(int, int, bool);
public:
	ratInMaze();
	System::String^ display ();
	void addBlock(int, int);
	void start();
	bool canMove(wchar_t);
	void move(wchar_t);
	bool back();
	bool done();
	void newMaze();
};

ratInMaze::ratInMaze()
{
	rat[0] = -1;
	rat[1] = -1;

	for (int x = 0; x < 10; x++)
		for (int y = 0; y < 10; y++)
			maze[x][y] = ' ';
}

void ratInMaze::move(int x, int y, bool save)
{
	if (rat[0] != -1 && rat[1] != -1 && save) {
		history[0].push(rat[0]);
		history[1].push(rat[1]);
	}

	rat[0] = x;
	rat[1] = y;
	maze[x][y] = 'O';
}

System::String^ ratInMaze::display ()
{
	System::String^ mazeDisplay;

	for (int i = 0; i < 10; i++)
	{
		if (i == 0 && rat[0] == -1 && rat[1] == -1)
			mazeDisplay += "O  ";
		else
			mazeDisplay += "   ";

		for (int j = 0 ; j < 10 ; j++)
		{
			mazeDisplay += "  " + maze[i][j] + "  ";

			if (j != 9) {
				mazeDisplay += "|" ;
			}
		}

		if (i == 9) 
			mazeDisplay += "   A";

		mazeDisplay += "\n" ;
		if (i != 9) {
			mazeDisplay += "   -----|-----|-----|-----|-----|-----|-----|-----|-----|-----\n" ;
		}
	}

	return mazeDisplay;
}

void ratInMaze::addBlock (int x, int y)
{
	maze[x][y] = '*';
}

void ratInMaze::start()
{
	history[0] = stack<int>(100);
	history[1] = stack<int>(100);

	move(0, 0, true);
}

bool ratInMaze::canMove(wchar_t dir)
{
	switch (dir)
	{
	case 'r':
		return (maze[rat[0]][rat[1] + 1] != '*' && maze[rat[0]][rat[1] + 1] != 'x' && maze[rat[0]][rat[1] + 1] != 'O' && rat[1] != 9);
	case 'l':
		return (maze[rat[0]][rat[1] - 1] != '*' && maze[rat[0]][rat[1] - 1] != 'x' && maze[rat[0]][rat[1] - 1] != 'O' && rat[1] != 0);
	case 'd':
		return (maze[rat[0] + 1][rat[1]] != '*' && maze[rat[0] + 1][rat[1]] != 'x' && maze[rat[0] + 1][rat[1]] != 'O' && rat[0] != 9);
	case 'u':
		return (maze[rat[0] - 1][rat[1]] != '*' && maze[rat[0] - 1][rat[1]] != 'x' && maze[rat[0] - 1][rat[1]] != 'O' && rat[0] != 0);
	default:
		return false;
	}
}

void ratInMaze::move(wchar_t dir)
{
	switch (dir)
	{
	case 'r':
		move(rat[0], rat[1] + 1, true);
		break;
	case 'l':
		move(rat[0], rat[1] - 1, true);
		break;
	case 'd':
		move(rat[0] + 1, rat[1], true);
		break;
	case 'u':
		move(rat[0] - 1, rat[1], true);
		break;
	}
}

bool ratInMaze::back()
{
	do
	{
		maze[rat[0]][rat[1]] = 'x';
		move(history[0].top(), history[1].top(), false);
		history[0].pop();
		history[1].pop();

		if (history[0].empty() && history[1].empty() && !canMove('d') && !canMove('r') && !canMove('l') && !canMove('u'))
			return false;

	} while (!canMove('d') && !canMove('r') && !canMove('l') && !canMove('u'));

	return true;
}

bool ratInMaze::done()
{
	return (rat[0] == 9 && rat[1] == 9);
}
