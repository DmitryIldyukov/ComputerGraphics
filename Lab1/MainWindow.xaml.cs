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

            LetterJumpAnimation(FirstName, 0);
            LetterJumpAnimation(Surname, 1);
            LetterJumpAnimation(Patronymic, 2);
        }

        private void LetterJumpAnimation(Canvas letter, double delay)
        {
            foreach (UIElement el in letter.Children)
            {
                if (el is Rectangle || el is Ellipse)
                {
                    DoubleAnimation animation = new DoubleAnimation
                    {
                        From = Canvas.GetTop(el),
                        To = Canvas.GetTop(el) + 50,
                        Duration = TimeSpan.FromSeconds(0.5),
                        AutoReverse = true,
                        RepeatBehavior = RepeatBehavior.Forever,
                        BeginTime = TimeSpan.FromSeconds(delay * 0.1),
                    };

                    Storyboard.SetTarget(animation, el);
                    Storyboard.SetTargetProperty(animation, new PropertyPath(Canvas.TopProperty));

                    Storyboard storyboard = new Storyboard();
                    storyboard.Children.Add(animation);

                    storyboard.Begin();
                }
            }
            
        }
    }
}
