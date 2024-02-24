using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Xml.Linq;

namespace Lab1
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void LetterJumpAnimation(object sender, MouseButtonEventArgs e)
        {
            const double acceleration = 30;
            const double height = 100;

            var letter = (Canvas)sender;

            foreach (UIElement el in letter.Children)
            {
                DoubleAnimation upAnimation = new DoubleAnimation
                {
                    From = Canvas.GetTop(el),
                    To = Canvas.GetTop(el) - height,
                    Duration = TimeSpan.FromSeconds(Math.Sqrt(2 * height / acceleration)),
                    DecelerationRatio = 1,
                };

                DoubleAnimation downAnimation = new DoubleAnimation
                {
                    From = Canvas.GetTop(el) - height,
                    To = Canvas.GetTop(el),
                    Duration = TimeSpan.FromSeconds(Math.Sqrt(2 * height / acceleration)),
                    AccelerationRatio = 1
                };

                upAnimation.Completed += (s, eventArgs) =>
                {
                    el.BeginAnimation(Canvas.TopProperty, downAnimation);
                };

                el.BeginAnimation(Canvas.TopProperty, upAnimation);
            }
        }
    }
}
