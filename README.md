# reVC-Injector-Payload
GTA Vice City reVC Trainer

Based on 247CTF's youtube video about "Hacking a game with DLL injection [Game Hacking 101]"
and implemented a keystroke method especially with an already built in cheat keycombo to the game.

The Injector will load the binary process application and once it gets a process ID it then injects our dll called payload.dll to memory within the game.

Cheats:

Numpad0 - Initializes the pointers based on static pointers and offsets found via Cheat Engine 
(yes it is still pretty good tool to have instead of reverse engineering the binary which takes time)

Numpad1 - triggers aspirine cheat via keystroke method that will send inputs as if you were typing them via keycombo but instead with 1 button.
Numpad2 - triggers bigbang cheat via keystroke method that will send inputs as if you were typing them via keycombo but instead with 1 button.
Numpad3 - triggers leavemealone cheat via keystroke method that will send inputs as if you were typing them via keycombo but instead with 1 button.

Anyways I couldn't be bothered adding all the cheats and if you look at the code how I did it, it is very tedious..
Plus this is only a POC(proof of concept) which shows that I understood how to hack a game.
