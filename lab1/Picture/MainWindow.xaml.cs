using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Picture
{
    public partial class MainWindow : Window
    {
        private bool isDragging;
        private Point offset;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Truck_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            isDragging = true;
            offset = e.GetPosition(truck);
            truck.CaptureMouse();
        }

        private void Truck_MouseMove(object sender, MouseEventArgs e)
        {
            if (isDragging)
            {
                Point currentPosition = e.GetPosition(mainGrid);
                var transform = new TranslateTransform(currentPosition.X - offset.X, currentPosition.Y - offset.Y);
                truck.RenderTransform = transform;
            }
        }

        private void Truck_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            isDragging = false;
            truck.ReleaseMouseCapture();
        }
    }
}
