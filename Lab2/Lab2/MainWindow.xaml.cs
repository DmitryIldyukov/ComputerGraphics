using System.Windows;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using Microsoft.Win32;
using Path = System.IO.Path;

namespace Lab2;

/// <summary>
/// Interaction logic for MainWindow.xaml
/// </summary>
public partial class MainWindow : Window
{
    private bool _isDragging;
    private Point _offset;
    
    public MainWindow()
    {
        InitializeComponent();
    }

    private void UploadImage_OnClick(object sender, RoutedEventArgs e)
    {
        OpenFileDialog dlg = new OpenFileDialog
        {
            DefaultExt = ".png",
            Filter = "Image files(*.png;*.jpg;*.bmp)|*.png;*.jpg;*.bmp"
        };
        
        if (dlg.ShowDialog() == true)
        {
            BitmapImage img = new BitmapImage(new Uri(dlg.FileName));
            if (Path.GetExtension(dlg.FileName).ToLower() == ".png")
            {
                ImageBrush imageBrush = new ImageBrush
                {
                    ImageSource = new BitmapImage(new Uri("background.png", UriKind.Relative))
                };
                ImageGrid.Background = imageBrush;
            }
            else
            {
                ImageGrid.Background = Brushes.Transparent;
            }
            Picture.Source = img;
        }
    }
    
    private void Picture_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
    {
        _isDragging = true;
        _offset = e.GetPosition(ImageGrid);
        ImageGrid.CaptureMouse();
    }

    private void Picture_MouseMove(object sender, MouseEventArgs e)
    {
        if (!_isDragging) return;
        var currentPosition = e.GetPosition(Container);
        var transform = new TranslateTransform(currentPosition.X - _offset.X, currentPosition.Y - _offset.Y);
        ImageGrid.RenderTransform = transform;
    }

    private void Picture_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
    {
        _isDragging = false;
        ImageGrid.ReleaseMouseCapture();
    }

    private void Picture_LostMouseCapture(object sender, MouseEventArgs e)
    {
        _isDragging = false;
    }
}