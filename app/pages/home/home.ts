import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { DetailPage } from '../detail/detail';
import { YoutubeService } from '../../providers/youtube-service/youtube-service';
import { Observable } from 'rxjs/Observable';
import { FORM_DIRECTIVES, FormControl } from '@angular/forms';

@Component({
  providers: [YoutubeService],
  directives: [FORM_DIRECTIVES],
  templateUrl: 'build/pages/home/home.html'

})
export class HomePage {
  videos: Observable<any[]>;
  searchInput = new FormControl();
  constructor(public navCtrl: NavController, private youtube: YoutubeService) {
    this.videos = youtube.load(this.searchInput.valueChanges
      //optionally debounce
      .debounceTime(300)
    );
  }

  itemTapped(event, video) {
    this.navCtrl.push(DetailPage, {
      video: video
    });
  }

}
