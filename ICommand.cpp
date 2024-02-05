#include "ICommand.h"

ICommand::~ICommand() {}

void RightCommand::Exec(Player& player) { player.MoveRight(); }

void LeftCommand::Exec(Player& player) { player.MoveLeft(); }
