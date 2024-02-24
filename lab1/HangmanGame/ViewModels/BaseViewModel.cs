using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace HangmanGame.ViewModels;

public class BaseViewModel : INotifyPropertyChanged
{
    public event PropertyChangedEventHandler PropertyChanged;

    protected virtual void OnPropertyChanged([CallerMemberName] string prop = null)
    {
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
    }

    protected virtual bool Set<T>(ref T field, T value, [CallerMemberName] string propName = null)
    {
        field = value;
        OnPropertyChanged(propName);
        return true;
    }

    protected static void NavigateToPage(Page page, Uri uri)
    {
        NavigationService.GetNavigationService(page).Navigate(uri);
    }
}