using System.Windows.Controls;

namespace HangmanGame.Commands;

public class NavigationCommand : BaseCommand
{
    private readonly Action<Page, Uri> _execute;
    private readonly Uri _uri;
        
    public NavigationCommand(Action<Page, Uri> execute, Uri uri)
    {
        _execute = execute;
        _uri = uri;
    }
        
    public override void Execute(object parameter)
    {
        _execute.Invoke((Page) parameter, _uri);
    }
}