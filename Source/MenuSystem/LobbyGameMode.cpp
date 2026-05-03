// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	if (GameState)
	{
		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();

		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Green, FString::Printf(TEXT("Number of Players: %d"), NumberOfPlayers));
		}

		APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>();
		if (PlayerState) {

			GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Cyan, FString::Printf(TEXT("%s HAS JOINED"), *PlayerState->GetPlayerName()));
		}




	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);


	if (GameState)
	{
		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();

		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Green, FString::Printf(TEXT("Number of Players: %d"), NumberOfPlayers-1));
		}
		APlayerState* PlayerState = Exiting->GetPlayerState<APlayerState>();
		if (PlayerState) {

			GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Cyan, FString::Printf(TEXT("%s HAS EXITED"), *PlayerState->GetPlayerName()));
		}
	}

}
