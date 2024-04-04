using System.IO;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Win32;
using System.Windows.Navigation;
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
        OpenFileDialog dlg = new OpenFileDialog();
        dlg.DefaultExt = ".png";
        dlg.Filter = "Image files (*.png;*.jpg;*.bmp)|*.png;*.jpg;*.bmp";
        
        if (dlg.ShowDialog() == true)
        {
            try
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
                Picture.Source = img;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Произошла ошибка загрузки изображения: {ex.Message}");
                throw;
            }
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
        if (_isDragging)
        {
            Point currentPosition = e.GetPosition(Container);
            var transform = new TranslateTransform(currentPosition.X - _offset.X, currentPosition.Y - _offset.Y);
            ImageGrid.RenderTransform = transform;
        }
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