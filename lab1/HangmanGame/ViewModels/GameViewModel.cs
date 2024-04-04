using HangmanGame.Models;

namespace HangmanGame.ViewModels;

public class GameViewModel : BaseViewModel
{
    private string _hiddenWord;
    private HangmanModel _hangmanModel;
    private Random _random;
        
    public GameViewModel()
    {
        _hangmanModel = new HangmanModel();
        _random = new Random();
    }
        
    public string HiddenWord { get => _hiddenWord; set => Set(ref _hiddenWord, value); }
}