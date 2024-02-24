using HangmanGame.Commands;

namespace HangmanGame.ViewModels;

public class MenuViewModel : BaseViewModel
{
    public NavigationCommand NavigateToGamePage { get => new NavigationCommand(NavigateToPage, new Uri("Views/Pages/GamePage.xaml", UriKind.RelativeOrAbsolute)); }
    public ApplicationExitCommand Exit { get => new ApplicationExitCommand(); }
}