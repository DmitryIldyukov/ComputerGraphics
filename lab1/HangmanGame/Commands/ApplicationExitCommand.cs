using System.Windows;

namespace HangmanGame.Commands;

public class ApplicationExitCommand : BaseCommand
{
    public override void Execute(object parameter)
    {
        var result = MessageBox.Show("Вы уверены, что хотите выйти из игры?", "Подтверждение", MessageBoxButton.YesNo, MessageBoxImage.Question);

        if (result == MessageBoxResult.Yes)
        {
            App.Current.Shutdown();
        }
    }
}